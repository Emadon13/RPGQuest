#include "itemfound.h"

using namespace std;

ItemFound::ItemFound():
    item()
{

}

ItemFound::ItemFound(string i):
    item(i)
{

}

Item ItemFound :: getItem()
{
    return ItemLoader::generate(item);
}

void ItemFound::addToInventory(Team* team)
{
    team->putInTheBag(item);
}


