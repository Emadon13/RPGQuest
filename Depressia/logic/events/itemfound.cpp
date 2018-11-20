#include "itemfound.h"

ItemFound::ItemFound():
    item()
{

}

ItemFound::ItemFound(Item i):
    item(i)
{

}

Item ItemFound :: getItem()
{
    return item;
}
