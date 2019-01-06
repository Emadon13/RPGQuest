#include "healitem.h"

using namespace std;

HealItem::HealItem():
    Item(),
    hpHeal(10)
{

}

HealItem::HealItem(std::string n, std::string d, std::string i, int hp):
    Item(n, d, i),
    hpHeal(hp)
{

}

HealItem::~HealItem()
{

}

std::string HealItem::use(Entity* target)
{   
    stringstream sstr;

    if(target->isAlive())
    {
        if(target->getHp()>=target->getHpMax())
            sstr << "Mais " << target->getName() << "a deja tous ses pvs...";

        else
        {
            sstr << Item::use(target) << "<br>" << target->getName() << " recupere " << hpHeal << " pvs ! ";
            target->restaureHp(hpHeal);
        }
    }

    else if(!target->isAlive())
        sstr << "Mais " << target->getName() << " est KO...";

   return sstr.str();
}

