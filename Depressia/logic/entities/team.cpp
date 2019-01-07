#include "team.h"

using namespace std;

Team::Team():
    bag(Inventory())
{
    hero[0] = dynamic_cast<Hero*>(EntityLoader::generate("../ressources/entities/heroes/bonasse.txt"));
    hero[1] = nullptr;//dynamic_cast<Hero*>(EntityLoader::generate("../ressources/entities/heroes/rouge.txt"));
    hero[2] = nullptr;//dynamic_cast<Hero*>(EntityLoader::generate("../ressources/entities/heroes/rozalin.txt"));
    hero[3] = nullptr;
}

Team::Team(Hero* e1, Hero* e2, Hero* e3, Hero* e4, Inventory b):
    bag(b)
{
    hero[0] = e1;
    hero[1] = e2;
    hero[2] = e3;
    hero[3] = e4;
}


int Team::getTeamSize()
{
    return teamSize;
}

Hero* Team::getHero(int i)
{
    if(i>=0 && i<teamSize)
        return hero[i];

    else
    {
        cout << "ERREUR : taille de tableau " << i << " dépassée pour team";
        return hero[0];
    }
}

Hero** Team::getHeroes()
{
    return hero;
}

Inventory* Team::getInventory()
{
    return &bag;
}

void Team::putInTheBag(string item)
{
    bag+item;
}
