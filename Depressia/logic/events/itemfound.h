#ifndef ITEMFOUND_H
#define ITEMFOUND_H

#include "logic/items/item.h"
#include "logic/events/event.h"

class ItemFound : public Event
{
public:
    ItemFound();
    ItemFound(Item i);
    Item getItem();

private:
    Item item;
};

#endif // ITEMFOUND_H
