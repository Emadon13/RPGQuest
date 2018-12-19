#include "healitem.h"

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
/*
std::string HealItem::use(Entity* user, Entity* target)
{
    target->restaureHp(hpHeal);
    return
}
*/
