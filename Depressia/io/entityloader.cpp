#include "entityloader.h"

using namespace std;

EntityLoader::EntityLoader()
{

}

Entity* EntityLoader::generate()
{
    return new Entity();
}

Entity* EntityLoader::generate(string path)
{
    ifstream file(path);
    string name, lvl, hpMax, mpMax, att, def, spd, sprite, icon, skill;
    vector<Skill*> skills;

    if(file)
    {
        getline(file, name);
        getline(file, lvl);
        getline(file, hpMax);
        getline(file, mpMax);
        getline(file, att);
        getline(file, def);
        getline(file, spd);
        getline(file, sprite);
        getline(file, icon);

        getline(file, skill);

        while(skill == "end")
            skills.push_back(SkillLoader::generate(skill));

        return new Entity(name,
                      int(stoi(lvl)),
                      int(stoi(hpMax)),
                      int(stoi(mpMax)),
                      int(stoi(att)),
                      int(stoi(def)),
                      int(stoi(spd)),
                      sprite,
                      icon,
                      skills);
    }

    else
    {
        cout << "ERREUR : entity " << path <<" non reconnue" << endl;
        return new Entity();
    }

}
