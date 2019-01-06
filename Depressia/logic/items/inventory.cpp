#include "inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory():
content(0)
{

}

Item* Inventory::getItem(int i)
{
    if(i > int(content.size()) || i< 0)
    {
        cout << "ERREUR : index inexistant" << endl;
        Item * basic = new Item();
        return basic;
    }

    else
    {
        return ItemLoader::generate(content.at(unsigned (i)));
    }
}
/*
void Inventory::putItem(string item)
{
    if(int(content.size()) >= max_size)
        cout << "ERREUR : inventaire plein";

    else
        content.push_back(item);
}
*/

void Inventory::deleteItem(int i)
{
    content.erase(content.begin() + i);
}

bool Inventory::isEmpty()
{
    return content.empty();
}

bool Inventory::isFull()
{
    return(content.size()>=max_size);
}

int Inventory::getSize()
{
    return int(content.size());
}

string Inventory::useItem(Entity* e, int i)
{
    string result = "L'index n'est pas bon !";

    if(i<max_size && i>=0)
    {
        result = ItemLoader::generate(content.at(unsigned(i)))->use(e);
        content.erase(content.begin() + i);
    }

    return result;
}

void Inventory::operator+(string item)
{
    if(int(content.size()) >= max_size)
        cout << "ERREUR : inventaire plein";

    else
        content.push_back(item);
}
