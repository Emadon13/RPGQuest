#include "fight.h"
#include "logic/entities/mob.h"

using namespace std;

Fight::Fight()
{

}

Fight::Fight(Hero* h[nb_e], Mob* m[nb_e], string img, string mus):
    music(mus),
    image(img)
{
    for(int i=0 ; i<nb_e ; i++)
    {
        heroes[i] = h[i];
        mobs[i] = m[i];
        all[i] = m[i];
        all[i+nb_e] = h[i];
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
    if(mobs[0]->getHp() == 0 &&
       mobs[1]->getHp() == 0 &&
       mobs[2]->getHp() == 0 &&
       mobs[3]->getHp() == 0)
        return true;

    else
        return false;
}

bool Fight::mobsWin()
{
    if(heroes[0]->getHp() == 0 &&
       heroes[1]->getHp() == 0 &&
       heroes[2]->getHp() == 0 &&
       heroes[3]->getHp() == 0)
        return true;

    else
        return false;
}

Entity* Fight::nextPlayer()
{
    for (int i=0 ; i<2*nb_e ; i++)
        if (speeds[i] >= speedLimit)
        {
            speeds[i] = 0;
            return all[i];
        }

    for (int i=0 ; i<2*nb_e ; i++)
        speeds[i] += all[i]->getSpd();

    return nextPlayer();
}
