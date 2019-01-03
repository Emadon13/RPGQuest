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
     sstr << Item::use(target) << "<br> target recupere " << hpHeal << " pvs ! ";
     target->restaureHp(hpHeal);
    return sstr.str();
}

