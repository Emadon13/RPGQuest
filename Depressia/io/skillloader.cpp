#include "skillloader.h"

using namespace std;

SkillLoader::SkillLoader()
{

}

Skill* SkillLoader::generate()
{
    return new Skill();
}

Skill* SkillLoader::generate(string path)
{
    ifstream file(path);
    string name, text, sprite, mpc, skill, ra, co, rng;

    if(file)
    {
        getline(file, name);
        getline(file, text);
        getline(file, sprite);
        getline(file, mpc);
        getline(file,rng);
        getline(file, skill);

        if(skill == "attack")
        {
            getline(file, co);
            return new Attack(name, text, sprite, int(stoi(mpc)), SkillLoader::compareRange(rng), float(stoi(co)));
        }

        else if(skill == "recover")
        {
            getline(file, co);
            return new Recover(name, text, sprite, int(stoi(mpc)), SkillLoader::compareRange(rng), float(stoi(co)));
        }

        else
        {
            cout << "ERREUR : type de skill non reconnu" << endl;
            return new Attack();
        }
    }

    else
    {
        cout << "ERREUR : fichier de sort " << path << " non trouvé ";
        return new Attack();
    }
}

Range SkillLoader::compareRange(string range)
{
    if (range == "self")
        return self;
    else if (range == "one_ally")
        return one_ally;
    else if (range == "one_enemy")
        return one_enemy;
    else if (range == "group_allies")
        return group_allies;
    else if (range == "group_enemies")
        return group_enemies;
    else if (range == "all_entities")
        return all_entities;
    else if (range == "several")
        return several;

    else
    {
        cout << "ERREUR : range inconnu" << endl;
        return one_enemy;
    }
}
