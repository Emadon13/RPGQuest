#include "skillloader.h"
#include "logic/skills/recover.h"
#include "logic/skills/recoil.h"

using namespace std;

SkillLoader::SkillLoader()
{

}
/*
Skill* SkillLoader::generate()
{
    return Skill();
}

Skill* SkillLoader::generate(string path)
{
    ifstream file(path);
    string name, text, mpc, skill, c, r, cat;
    int mpCost, coef, rate;

    if(file)
    {
        getline(file, name);
        getline(file, text);
        getline(file, mpc);
        mpCost = int(stoi(mpc));

        getline(file,skill);

        if(skill == "recover")
        {
            getline(file,c);
            getline(file, r);

            coef = int(stoi(c));

            getline(file, cat);
            while (cat != "end")

            return new Recover(name, text, mpCost, coef);
        }
    }

}
*/
