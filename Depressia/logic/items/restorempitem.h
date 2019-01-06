#ifndef RESTOREMPITEM_H
#define RESTOREMPITEM_H

#include "logic/items/item.h"

class RestoreMpItem : public Item
{
public:
    RestoreMpItem();
    RestoreMpItem(std::string n, std::string d, std::string i, int mp);
    virtual ~RestoreMpItem();

    std::string  use(Entity*);


private:
    int mpHeal;
};

#endif // RESTOREMPITEM_H
