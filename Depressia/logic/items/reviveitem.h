#ifndef REVIVEITEM_H
#define REVIVEITEM_H

#include "logic/items/item.h"

class ReviveItem : public Item
{
public:
    ReviveItem();
    ReviveItem(std::string n, std::string d, std::string i, int hp);
    virtual ~ReviveItem();

    std::string use(Entity*);

private:
    int hpHeal;
};

#endif // REVIVEITEM_H
