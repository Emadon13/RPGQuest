#include "fight.h"
#include "logic/entities/mob.h"
#include "logic/entities/team.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   Fight                          ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class Fight

    Cette classe représente un type d'envent particulier, le combat qui se caractérise par :
        - une team de heros
        - des ennemis
        - une musique
        - une image de fond

     Ses différentes méthodes sont :
        - des getters : pour savoir si le combat est finit, la musique, ...
        - nextPlayer() : au debut de chaque nouveau tour dans le combta, cette méthode est appelée et définie qui est l'entité qui va jouer ce tour
        ci (en fonction de sa stat de vitesse et des autres joueurs qui ont joués avant)
        - useItem() : qui permet à une entite d'untiliser un item (un effet sera appliqué et l'item retiré de l'inventaire
        - target() : permet de lancer un sort ou une attaque sur une entite, en fonction de la puissance de l'entite qui attaque, de celle qui defend, des differents boosts appliqués,
        du type de sort(soin, degat, ...). ! un sort peut échouer
*/

using namespace std;

Fight::Fight():
    Event()
{

}

Fight::Fight(Team* t, Mob* m[nb_e], string img, string mus):
    Event(),
    music(mus),
    image(img)
{

    for(int i=0 ; i<nb_e ; i++)
    {
        heroes[i] = t->getHero(i);
        tHeroes[i] = t->getHero(i);
        mobs[i] = m[i];
        tMobs[i] = m[i];
        all[i] = m[i];
        all[i+nb_e] = t->getHero(i);
        speeds[i] = 0;
        speeds[i+nb_e] = 0;
        team = t;
    }
}

Hero** Fight::getHeroes()
{
    return heroes;
}

Mob** Fight::getMobs()
{
    return mobs;
}

Entity** Fight::getAll()
{
    return all;
}

bool Fight::teamWin()
{
    for(int i=0 ; i<nb_e ; i++)
        if(mobs[i]!=nullptr)
            if(mobs[i]->isAlive())
                return false;
    return true;
}

bool Fight::mobsWin()
{
    for(int i=0 ; i<nb_e ; i++)
        if(heroes[i]!=nullptr)
            if(heroes[i]->isAlive())
                return false;
    return true;
}

bool Fight::isEnded()
{
    return(teamWin() || mobsWin());
}

Entity* Fight::nextPlayer()
{
    speedLimit = 0;
    int maxSpeed = 0;

    for (int i=0 ; i<2*nb_e ; i++)
        if (all[i] != nullptr)
            if(all[i]->isAlive())
                speedLimit += int(all[i]->getSpd());

    for (int i=0 ; i<2*nb_e ; i++)
        if(speeds[i] > speeds[maxSpeed])
                maxSpeed = i;

    if(all[maxSpeed] != nullptr)
    {
        if(all[maxSpeed]->isAlive())
        {
            if(speeds[maxSpeed] >= speedLimit)
            {
                speeds[maxSpeed] = 0;

                return all[maxSpeed];
            }
        }
    }

    for (int i=0 ; i<2*nb_e ; i++)
    {
        if (all[i] != nullptr)
            if(all[i]->isAlive())
                speeds[i] += int(float(all[i]->getSpd())*float(all[i]->getBuffs()->getCoef(buffSpeed)));
    }

    return nextPlayer();
}

vector<Entity*> Fight::target(Mob* user, int skill)
{
    vector<Entity*> v(0);

    if(user->getMove(skill)->getRange() == self)
        v = vector<Entity*>(1,user);

    else if(user->getMove(skill)->getRange() == one_ally)
        v = vector<Entity*>(1,user->chooseEntity(tMobs));

    else if(user->getMove(skill)->getRange() == one_enemy)
        v = vector<Entity*>(1,user->chooseEntity(tHeroes));

    else if(user->getMove(skill)->getRange() == group_allies)
        v = vectorizeM();

    else if(user->getMove(skill)->getRange() == group_enemies)
        v = vectorizeH();

    else if(user->getMove(skill)->getRange() == all_entities)
        v = vectoriezA();

    user->getMove(skill)->call(dynamic_cast<Entity*>(user), v);
    return v;
}

vector<Entity*> Fight::target(Hero* user, int skill)
{
    vector<Entity*> v(0);

    if(user->getMove(skill)->getRange() == self)
        v = vector<Entity*>(1,user);

    else if(user->getMove(skill)->getRange() == group_allies)
        v = vectorizeH();

    else if(user->getMove(skill)->getRange() == group_enemies)
        v = vectorizeM();

    else if(user->getMove(skill)->getRange() == all_entities)
        v = vectoriezA();

    user->getMove(skill)->call(dynamic_cast<Entity*>(user), v);
    return v;
}

vector<Entity*> Fight::target(Hero* user, int skill, int target)
{
    vector<Entity*> v(0);

    if(user->getMove(skill)->getRange() == one_ally)
        v = vector<Entity*>(1, heroes[target]);

    else if(user->getMove(skill)->getRange() == one_enemy)
        v = vector<Entity*>(1, mobs[target]);

    user->getMove(skill)->call(dynamic_cast<Entity*>(user), v);
    return v;
}

string Fight::useItem(Entity* entity, int item)
{
    return team->getInventory()->useItem(entity, item);
}

QPixmap* Fight::getImage()
{
    return new QPixmap(QPixmapLoader::generate(image));
}

QUrl* Fight::getMusic()
{
    return new QUrl(QString::fromStdString(music));
}

std::vector<Entity*> Fight::vectorizeH()
{
    vector<Entity*> e;
    for(int i=0 ; i<nb_e ; i++)
        if(heroes[i] != nullptr)
            if(heroes[i]->isAlive())
                e.push_back(heroes[i]);
    return e;
}

std::vector<Entity*> Fight::vectorizeM()
{
    vector<Entity*> e;
    for(int i=0 ; i<nb_e ; i++)
        if(mobs[i] != nullptr)
            if(mobs[i]->isAlive())
                e.push_back(mobs[i]);
    return e;
}

std::vector<Entity*> Fight::vectoriezA()
{
    vector<Entity*> e;
    for(int i=0 ; i<nb_e*2 ; i++)
        if(all[i] != nullptr)
            if(all[i]->isAlive())
                e.push_back(all[i]);
    return e;
}
