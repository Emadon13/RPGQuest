#include "entityloader.h"

using namespace std;

EntityLoader::EntityLoader()
{

}


EntityLoader::~EntityLoader()
{

}


Entity EntityLoader::generate()
{
    return Entity();
}

Entity EntityLoader::generate(string path)
{
    string name;
    int level;
    int hpMax;
    int mpMax;
    int hp;
    int mp;
    int att;
    int def;
    int spd;
    vector<Skill> skills(0);

    ifstream file(path);
    string line;

    if(file)
    {
        file >> name >> level >> hpMax >> mpMax >> hp >> mp >> att >> def >> spd;
        file.close();

        return Entity(name, level, hpMax, mpMax, hp, mp, att, def, spd, skills);
    }

    else
    {
        std::cout << "marche paaaas" << std::endl;
        Entity e;
        return e;
    }
}
