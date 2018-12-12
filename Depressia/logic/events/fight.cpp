#include "fight.h"
#include "logic/entities/mob.h"
#include "logic/entities/team.h"

using namespace std;

Fight::Fight()
{

}

Fight::Fight(Team* t, Mob* m[nb_e], string img, string mus):
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
    int totalHp = 0;
    for(int i=0 ; i<nb_e ; i++)
        if(mobs[i] != nullptr)
            totalHp+=mobs[i]->getHp();
    if(totalHp <= 0)
     {
        cout << "les heros ont gagné" << endl;
        return true;
     }

    return false;
}

bool Fight::mobsWin()
{
    int totalHp = 0;
    for(int i=0 ; i<nb_e ; i++)
        if(heroes[i] != nullptr)
            totalHp+=heroes[i]->getHp();
    if(totalHp <= 0)
     {
        cout << "les mobs ont gagné" << endl;
        return true;
     }
    return false;
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
            if(all[i]->getHp() > 0)
                speedLimit += all[i]->getSpd();

    for (int i=0 ; i<2*nb_e ; i++)
        if(speeds[i] > speeds[maxSpeed])
                maxSpeed = i;

    if(all[maxSpeed] != nullptr)
    {
        if(speeds[maxSpeed] >= speedLimit)
        {
            speeds[maxSpeed] = 0;
            return all[maxSpeed];
        }
    }

    for (int i=0 ; i<2*nb_e ; i++)
    {
        if (all[i] != nullptr)
            if(all[i]->getHp() > 0)
                speeds[i] += all[i]->getSpd();
    }


    return nextPlayer();
}

void Fight::target(Mob* user, int skill)
{

    if(user->getMove(skill)->getRange() == self)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vector<Entity*>(1,user));

    else if(user->getMove(skill)->getRange() == one_ally)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vector<Entity*>(1,user->chooseEntity(tMobs)));

    else if(user->getMove(skill)->getRange() == one_enemy)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vector<Entity*>(1,user->chooseEntity(tHeroes)));

    else if(user->getMove(skill)->getRange() == group_allies)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vectorizeM());

    else if(user->getMove(skill)->getRange() == group_enemies)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vectorizeH());

    else if(user->getMove(skill)->getRange() == all_entities)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vectoriezA());
}

void Fight::target(Hero* user, int skill)
{
    if(user->getMove(skill)->getRange() == self)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vector<Entity*>(1,user));

    else if(user->getMove(skill)->getRange() == group_allies)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vectorizeM());

    else if(user->getMove(skill)->getRange() == group_enemies)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vectorizeH());

    else if(user->getMove(skill)->getRange() == all_entities)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vectoriezA());
}

void Fight::target(Hero* user, int skill, int target)
{
    if(user->getMove(skill)->getRange() == one_ally)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vector<Entity*>(1, heroes[target]));

    else if(user->getMove(skill)->getRange() == one_enemy)
        user->getMove(skill)->call(dynamic_cast<Entity*>(user), vector<Entity*>(1, mobs[target]));
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
            e.push_back(heroes[i]);
    return e;
}

std::vector<Entity*> Fight::vectorizeM()
{
    vector<Entity*> e;
    for(int i=0 ; i<nb_e ; i++)
        if(mobs[i] != nullptr)
            e.push_back(mobs[i]);
    return e;
}

std::vector<Entity*> Fight::vectoriezA()
{
    vector<Entity*> e;
    for(int i=0 ; i<nb_e*2 ; i++)
        if(all[i] != nullptr)
            e.push_back(all[i]);
    return e;
}
