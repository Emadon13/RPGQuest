#include "itemfound.h"

using namespace std;

ItemFound::ItemFound():
    Event(),
    item()
{
    redo = false;
}

ItemFound::ItemFound(string i):
    Event(),
    item(i)
{
    redo = false;
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


