#include "fight.h"

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

Entity** Fight::getHeroes()
{
    return heroes;
}

Entity** Fight::getMobs()
{
    return mobs;
}

Entity** Fight::getAll()
{
    return all;
}
