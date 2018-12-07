#include "team.h"

using namespace std;

Team::Team():
    bag(Inventory())
{
    hero[0] = dynamic_cast<Hero*>(EntityLoader::generate("../ressources/entities/heroes/bonasse.txt"));
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
