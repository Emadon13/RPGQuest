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
    string name, lvl, hpMax, mpMax, att, def, spd, spriten, sprited, spritea, sprites, spritek, icon, skill, nbSkill;
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
        getline(file, spriten);
        getline(file, sprited);
        getline(file, spritea);
        getline(file, sprites);
        getline(file, spritek);
        getline(file, icon);

        getline(file, skill);

        while(skill != "end_skill")
        {
            skills.push_back(SkillLoader::generate(skill));
            getline(file, skill);
        }

        if(path.find("heroes") != string::npos)
        {
            string stl[Entity::max_lvl];

            getline(file, nbSkill);

            while(nbSkill != "end")
            {
                getline(file, skill);
                stl[int(stoi(nbSkill))] = skill;
                getline(file, nbSkill);
            }


            Hero* hero = new Hero(name,
                          int(stoi(lvl)),
                          int(stoi(hpMax)),
                          int(stoi(mpMax)),
                          int(stoi(att)),
                          int(stoi(def)),
                          int(stoi(spd)),
                          spriten,
                          sprited,
                          spritea,
                          sprites,
                          spritek,
                          icon,
                          skills,
                          stl,
                          path);
            return hero;
        }

        else
            return new Mob(name,
                           int(stoi(lvl)),
                           int(stoi(hpMax)),
                           int(stoi(mpMax)),
                           int(stoi(att)),
                           int(stoi(def)),
                           int(stoi(spd)),
                           spriten,
                           sprited,
                           spritea,
                           sprites,
                           spritek,
                           icon,
                           skills);
    }

    else
    {
        cout << "ERREUR : entity " << path <<" non reconnue" << endl;
        return new Entity();
    }

}
