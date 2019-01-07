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

    Team* team;

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


    team = new Team(heroes[0], heroes[1], heroes[2], heroes[3], invt);
    getline(file, pos);
    getline(file, mp);

    map = MapLoader::generate(team, mp);

    map.setCurrentPosition(stoi(pos));

    getline(file, evntHapp);

    while(evntHapp != "end_eventHapp")
    {
        map.setEventHapp(stoi(evntHapp));
        getline(file, evntHapp);
    }


    return Game(map, team);
}

void GameLoader::save(Game game)
{
    string path = "../ressources/save/save.vincent";
    ofstream file(path);

    for(int i=0 ; i<4 ; i++)
    {
        if(game.getTeam()->getHero(i)==nullptr)
            file << "none" << endl;

        else
        {
            file << game.getTeam()->getHero(i)->getSaveLink() << endl;
            file << game.getTeam()->getHero(i)->getXp() << endl;
            file << (game.getTeam()->getHero(i)->getHpMax() - game.getTeam()->getHero(i)->getHp()) << endl;
            file << (game.getTeam()->getHero(i)->getMpMax() - game.getTeam()->getHero(i)->getMp()) << endl;
        }

    }

    for(int i=0 ; i<game.getTeam()->getInventory()->getSize() ; i++)
        file << game.getTeam()->getInventory()->getItemPath(i) << endl;

    file << "end_inventory" << endl;
    file << game.getMap()->currentPosition << endl;
    file << "../ressources/maps/map.txt" << endl;

    for(int i=0 ; i<game.getMap()->getNbElements() ; i++)
        if(game.getMap()->isEventHapp(i))
            file << i << endl;

    file << "end_eventHapp";
}
