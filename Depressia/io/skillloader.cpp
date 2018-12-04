#include "skillloader.h"
#include "logic/skills/recover.h"
#include "logic/skills/recoil.h"

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
    string name, text, mpc, skill, co, ra, rng;
    int mpCost, coef, rate;

    if(file)
    {
        getline(file, name);
        getline(file, text);
        getline(file, mpc);
        mpCost = int(stoi(mpc));

        getline(file,skill);

        if(skill == "attack")
        {
            getline(file, rng);
            getline(file, co);
        }

        if(skill == "recover")
        {
            getline(file,rng);
            getline(file, co);

            coef = int(stoi(co));
            return new Skill();

            //return new Recover(name, text, mpCost, coef);
        }
    }

}

