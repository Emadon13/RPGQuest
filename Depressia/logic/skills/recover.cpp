#include "recover.h"

using namespace std;

Recover::Recover()
{
    name = "Soin";
    description = "Un sort de soin basique";
    coef = 1.;
    categories.push_back(heal);
}

Recover::Recover(double m_coef)
{
    name = "Soin";
    description = "Un sort de soin basique";
    coef = m_coef;
    categories.push_back(heal);
}

Recover::Recover(string m_name, string m_description, double m_coef)
{
    name = m_name;
    description = m_description;
    coef = m_coef;
    categories.push_back(heal);
}

vector<int> Recover::call(Entity& user, vector<Entity> targets)
{
    vector<int> hpHeals;
    for (unsigned long long i=0 ; i<targets.size() ; i++)
    {
        int hpHeal;
        hpHeal = int((user.getLvl() * 2 + targets.at(i).getLvl()) * coef);
        hpHeals.push_back(hpHeal);
    }

    return hpHeals;

}
