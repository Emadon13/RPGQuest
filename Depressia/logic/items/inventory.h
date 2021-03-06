#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<vector>
#include<io/itemloader.h>

class Inventory
{
public:
    Inventory();

    Item* getItem(int i);
    //void putItem(std::string item);
    bool isEmpty();
    bool isFull();
    int getSize();
    std::string getItemPath(int i);
    void deleteItem(int i);
    void operator+(std::string item);
    std::string useItem(Entity* e, int i);


private:
    static const int max_size = 8;
    std::vector<std::string> content;

};

#endif // INVENTORY_H
