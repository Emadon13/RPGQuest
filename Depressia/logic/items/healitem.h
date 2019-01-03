#ifndef HEALITEM_H
#define HEALITEM_H

#include "logic/items/item.h"

class HealItem : public Item
{
public:
    HealItem();
    HealItem(std::string n, std::string d, std::string i, int hp);
    virtual ~HealItem();

    std::string  use(Entity*);

//    std::string use(Entity*);

private:
    int hpHeal;
};

#endif // HEALITEM_H
