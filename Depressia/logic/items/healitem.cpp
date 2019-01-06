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

     if(!target->isAlive())
     {
         sstr << Item::use(target) << "<br>" << target->getName() << " est de retour parmi nous !";
         target->restaureHp(hpHeal);
     }

     else
         sstr << "Mais " << target->getName() << " est toujours en vie...";

    return sstr.str();
}

