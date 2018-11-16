#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<vector>
#include"logic/items/item.h"

class Inventory
{
public:
    Inventory();

    Item getItem(int i);
    void putItem(Item item);
    bool isEmpty();

private:
    static const int max_size = 8;
    std::vector<Item> content;
};

#endif // INVENTORY_H
