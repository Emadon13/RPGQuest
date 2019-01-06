#ifndef ITEMFOUND_H
#define ITEMFOUND_H

#include"io/itemloader.h"
#include "logic/events/event.h"
#include "logic/entities/team.h"

class ItemFound : public Event
{
public:
    ItemFound();
    ItemFound(std::string i);
    Item getItem();
    void addToInventory(Team* team);

private:
    std::string item;
};

#endif // ITEMFOUND_H
