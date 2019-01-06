#include "itemfound.h"

using namespace std;

ItemFound::ItemFound():
    Event(),
    item()
{
    redo = true;
}

ItemFound::ItemFound(string i):
    Event(),
    item(i)
{
    redo = true;
}

Item* ItemFound::getItem()
{
    return ItemLoader::generate(item);
}

void ItemFound::addToInventory(Team* team)
{
    if(!team->getInventory()->isFull())
    {
        team->putInTheBag(item);
        redo = false;
    }
}


