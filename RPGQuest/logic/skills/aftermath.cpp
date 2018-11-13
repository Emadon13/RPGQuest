#include "aftermath.h"

using namespace std;

Aftermath::Aftermath()
{
    name = "Vampipoutou";
    description = "Baiser qui restaure 1/2 des dégats infligés";
    coef = 1.;
    rate = -0.5;
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

int Aftermath::call()
{
    /*
    for(int i =0; i < sizeof(target) ; i++){
        int drain;
        drain = int(attacker.hitOpponent(target,coef) * rate);
        attacker.takeDamage(drain);
        return drain;
    }
    */
    return 0;

}
