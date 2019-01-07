#include "gameloader.h"

using namespace std;
GameLoader::GameLoader()
{

}

Game GameLoader::generate(string path)
{
    ifstream file(path);
    string link, xp, hpLost, mpLost, item, mp, pos, evntHapp;
    Hero* heroes[4];
    Inventory invt;
    Map map;

    Team team;

    for(int i=0 ; i<4 ; i++)
    {
        getline(file, link);
        if(link != "none")
        {
            getline(file, xp);
            getline(file, hpLost);
            getline(file, mpLost);
            heroes[i] = dynamic_cast<Hero*>(EntityLoader::generate(link));
            heroes[i]->addXp(stoi(xp));
            heroes[i]->takeDamage(stoi(hpLost));
            heroes[i]->loseMp(stoi(hpLost));
        }

        else
            heroes[i] = nullptr;
     }

    getline(file, item);

    while(item != "end_inventory")
    {
        invt + item;
        getline(file, item);
    }


    team = Team(heroes[0], heroes[1], heroes[2], heroes[3], invt);
    getline(file, pos);
    getline(file, mp);

    map = MapLoader::generate(&team, mp);

    map.setCurrentPosition(stoi(pos));

    getline(file, evntHapp);

    while(evntHapp != "end_eventHapp")
    {
        map.setEventHapp(stoi(evntHapp));
        getline(file, evntHapp);
    }


    return Game(map, team);
}
