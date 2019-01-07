#include "save.h"

Save::Save():
    Event()
{
    redo = true;
}

void Save::heal(Team* team)
{
    for(int i=0 ; i<4 ; i++)
        if(team->getHero(i)!=nullptr)
        {
            team->getHero(i)->restaureHp(team->getHero(i)->getHpMax()-team->getHero(i)->getHp());
            team->getHero(i)->restaureMp(team->getHero(i)->getMpMax()-team->getHero(i)->getMp());
        }
}

void Save::save(Game* game)
{
    GameLoader::save(*game);
}
