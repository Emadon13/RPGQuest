#include "fight.h"
#include "logic/entities/mob.h"
#include "logic/entities/team.h"

using namespace std;

Fight::Fight()
{

}

Fight::Fight(Team* team, Mob* m[nb_e], string img, string mus):
    music(mus),
    image(img)
{
    for(int i=0 ; i<nb_e ; i++)
    {
        heroes[i] = team->getHero(i);
        mobs[i] = m[i];
        all[i] = m[i];
        all[i+nb_e] = team->getHero(i);
        speeds[i] = 0;
        speeds[i*2] = 0;
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
        if(mobs[i] != nullptr)
            if(mobs[i]->getHp() <= 0)
                return true;
    return false;
}

bool Fight::mobsWin()
{
    for(int i=0 ; i<nb_e ; i++)
        if(heroes[i] != nullptr)
            if(heroes[i]->getHp() <= 0)
                return true;
    return false;
}

bool Fight::isEnded()
{
    return(teamWin() || mobsWin());
}

Entity* Fight::nextPlayer()
{
    speedLimit = 0;

    for (int i=0 ; i<2*nb_e ; i++)
        if (all[i] != nullptr)
            if(all[i]->getHp() > 0)
                speedLimit += all[i]->getSpd();


    cout << "speedLimit : " << speedLimit << endl;


    for (int i=0 ; i<2*nb_e ; i++)
        if (speeds[i] >= speedLimit)
        {
            speeds[i] = 0;
            return all[i];
        }

    for (int i=0 ; i<2*nb_e ; i++)
    {
        if (all[i] != nullptr)
            if(all[i]->getHp() > 0)
                speeds[i] += all[i]->getSpd();
        cout << speeds[i] << " ";
    }
    cout << endl;

    return nextPlayer();
}

QPixmap* Fight::getImage()
{
    return new QPixmap(QPixmapLoader::generate(image));
}

QUrl* Fight::getMusic()
{
    return new QUrl(QString::fromStdString(music));
}
