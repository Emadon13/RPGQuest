#include "recover.h"

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

Recover::Recover(std::string m_name, std::string m_description, double m_coef)
{
    name = m_name;
    description = m_description;
    coef = m_coef;
    categories.push_back(heal);
}
