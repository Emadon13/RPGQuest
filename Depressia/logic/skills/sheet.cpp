#include "sheet.h"

using namespace std;

Sheet::Sheet()
{

}

Sheet::Sheet(string u,
             string sn,
             vector<string> t,
             bool is,
             vector<int> d,
             int a,
             vector<HitEffect> he,
             SkillType st):
    user(u),
    skillName(sn),
    targets(t),
    isSkill(is),
    damages(d),
    aftermath(a),
    hitEffects(he),
    skillType(st)
{

}



vector<string> Sheet::toString()
{
    std::stringstream sstr;
    vector<string> strings;

    if(isSkill == false)
    {
        for (unsigned int i=0 ; i<targets.size() ; i++)
        {
            sstr.clear();
            sstr << user << " attaque " << targets.at(i) << " !";

            if(hitEffects.at(i) == miss)
                sstr << "<br>Mais échoué !";

            else if(hitEffects.at(i) == critical)
                sstr << "<br>COUP CRITIQUE !<br>" << damages.at(i) << " dégats infligés !";

            else
                sstr << "<br>" << damages.at(i) << " dégats infligés !";
            strings.push_back(sstr.str());
        }

    }

    else
    {

        if(skillType == recover)
        {
            for (unsigned int i=0 ; i<targets.size() ; i++)
            {
                sstr.clear();
                sstr << user << " utilise " << skillName << " sur " << targets.at(i) << " !<br>" << damages.at(i) << " PVs restaurés !";
                strings.push_back(sstr.str());
            }
        }

        else if(skillType == attack)
        {
            for (unsigned int i=0 ; i<targets.size() ; i++)
            {
                sstr.clear();
                sstr << user << " utilise " << skillName << " sur " << targets.at(i) << " !";
                if(hitEffects.at(i) == miss)
                    sstr << "<br>Mais échoué !";

                else if(hitEffects.at(i) == critical)
                    sstr << "<br>COUP CRITIQUE !<br>" << damages.at(i) << " dégats infligés !";

                else
                    sstr << "<br>" << damages.at(i) << " dégats infligés !";

                strings.push_back(sstr.str());
            }
        }

        else if(skillType == drain)
        {
            for (unsigned int i=0 ; i<targets.size() ; i++)
            {
                sstr.clear();
                sstr << user << " utilise " << skillName << " sur " << targets.at(i) << " !";
                if(hitEffects.at(i) == miss)
                    sstr << "<br>Mais échoué !";

                else if(hitEffects.at(i) == critical)
                    sstr << "<br>COUP CRITIQUE !<br>" << damages.at(i) << " dégats infligés !";

                else
                    sstr << "<br>" << damages.at(i) << " dégats infligés !";

                strings.push_back(sstr.str());
            }
            sstr.clear();
            sstr << "<br>" << aftermath << " PVs drainés !";
            strings.push_back(sstr.str());
        }

        else if(skillType == recoil)
        {
            for (unsigned int i=0 ; i<targets.size() ; i++)
            {
                sstr.clear();
                sstr << user << " utilise " << skillName << " sur " << targets.at(i) << " !";
                if(hitEffects.at(i) == miss)
                    sstr << "<br>Mais échoué !";

                else if(hitEffects.at(i) == critical)
                    sstr << "<br>COUP CRITIQUE !<br>" << damages.at(i) << " dégats infligés !";

                else
                    sstr << "<br>" << damages.at(i) << " dégats infligés !";

                strings.push_back(sstr.str());
            }
            sstr.clear();
            sstr << "<br>" << aftermath << " PVs de recul !";
            strings.push_back(sstr.str());
        }
    }

    return strings;
}
