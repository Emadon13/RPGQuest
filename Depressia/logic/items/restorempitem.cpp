#include "restorempitem.h"

using namespace std;

RestoreMpItem::RestoreMpItem():
    Item(),
    mpHeal(10)
{

}

RestoreMpItem::RestoreMpItem(std::string n, std::string d, std::string i, int hp):
    Item(n, d, i),
    mpHeal(hp)
{

}

RestoreMpItem::~RestoreMpItem()
{

}

std::string RestoreMpItem::use(Entity* target)
{
     stringstream sstr;

     if(target->isAlive())
     {
         if(target->getMp()>=target->getMpMax())
             sstr << "Mais " << target->getName() << "a deja tous ses pms...";

         else
         {
             sstr << Item::use(target) << "<br>" << target->getName() << " recupere " << mpHeal << " pms ! ";
             target->restaureMp(mpHeal);
         }
     }

     else
         sstr << "Mais " << target->getName() << " est KO...";

    return sstr.str();
}
