#include "reviveitem.h"

using namespace std;

ReviveItem::ReviveItem():
    Item(),
    hpHeal(10)
{

}

ReviveItem::ReviveItem(std::string n, std::string d, std::string i, int hp):
    Item(n, d, i),
    hpHeal(hp)
{

}

ReviveItem::~ReviveItem()
{

}

std::string ReviveItem::use(Entity* target)
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
