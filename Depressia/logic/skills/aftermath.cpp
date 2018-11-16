 #include "aftermath.h"

using namespace std;

Aftermath::Aftermath()
{
    name = "Vampipoutou";
    description = "Baiser qui restaure 1/2 des dégats infligés";
    coef = 1.;
    rate = -0.5;
    categories.push_back(drain);

}

Aftermath::Aftermath(double m_coef, double m_rate)
{
    if (m_rate >= 0)
    {
        name = "Drain";
        description = "Rend une partie des dégats infligés";
    }

    else
    {
        name = "Bélier";
        description = "Inflige au lanceur des dégats de recul";
    }

    coef = m_coef;
    rate = m_rate;
}

Aftermath::Aftermath(string m_name, string m_description, double m_coef, double m_rate)
{
    name = m_name;
    description = m_description;
    coef = m_coef;
    rate = m_rate;
}


Aftermath::~Aftermath()
{
}

vector<int> Aftermath::call(Entity& user, vector <Entity> targets)
{
    vector<int> drains;

    for(unsigned long long i=0 ; i < targets.size() ; i++)
    {
        int drain;
        drain = int(user.hitOpponent(targets.at(i)) * rate);
        user.takeDamage(drain);
        drains.push_back(drain);
    }

    return drains;
}
