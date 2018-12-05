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
    string name, lvl, hpMax, mpMax, att, def, spd, spriteN, spriteD, spriteA, spriteS, spriteK, skill;
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
        getline(file, spriteN);
        getline(file, spriteD);
        getline(file, spriteA);
        getline(file, spriteS);
        getline(file, spriteK);

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
                      new Sprite(spriteN, spriteD, spriteA, spriteS, spriteK),
                      skills);
    }

    else
    {
        cout << "ERREUR : entity " << path <<" non reconnue" << endl;
        return new Entity();
    }

}
