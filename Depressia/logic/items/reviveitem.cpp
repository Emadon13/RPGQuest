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
