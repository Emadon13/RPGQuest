#include "fightloader.h"

using namespace std;

FightLoader::FightLoader()
{

}

Fight FightLoader::generate()
{
    return Fight();
}

Fight FightLoader::generate(Team* team, string path)
{
    ifstream file(path);
    string m1, m2, m3, m4, background, music;
    Mob *mobs[4];

    if(file)
    {
        getline(file, m1);
        getline(file, m2);
        getline(file, m3);
        getline(file, m4);

        if(m1 == "none")
            mobs[0] =  nullptr;
        else
            mobs[0] = (dynamic_cast<Mob*>(EntityLoader::generate(m1)));

        if(m2 == "none")
            mobs[1] =  nullptr;
        else
            mobs[1] = (dynamic_cast<Mob*>(EntityLoader::generate(m2)));

        if(m3 == "none")
            mobs[2] =  nullptr;
        else
            mobs[2] = (dynamic_cast<Mob*>(EntityLoader::generate(m3)));

        if(m4 == "none")
            mobs[3] =  nullptr;
        else
            mobs[3] = (dynamic_cast<Mob*>(EntityLoader::generate(m4)));

        getline(file, background);
        getline(file, music);

        return Fight(team, mobs, background, music);
    }

    else
    {
        cout << "ERREUR : fight '" << path << "' introuvable";
        return Fight();
    }
}
