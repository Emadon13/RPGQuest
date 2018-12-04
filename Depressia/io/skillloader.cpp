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
    string name, text, mpc, skill, ra, co, rng;

    if(file)
    {
        getline(file, name);
        getline(file, text);
        getline(file, mpc);
        getline(file,skill);
        getline(file, rng);

        if(skill == "attack")
        {
            getline(file, co);
            return new Attack(name, text, int(stoi(mpc)), SkillLoader::compareRange(rng), double(stoi(co)));
        }

        else if(skill == "recover")
        {
            getline(file, co);
            return new Recover(name, text, int(stoi(mpc)), SkillLoader::compareRange(rng), double(stoi(co)));
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
    if (range == "one")
        return one;
    else if (range == "several")
        return several;
    else if (range == "group")
        return group;
    else if (range == "all")
        return all;

    else
    {
        cout << "ERREUR : range inconnu" << endl;
        return one;
    }
}
