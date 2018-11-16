#include "inventory.h"

using namespace std;
Inventory::Inventory():
content(0)
{

}

Item Inventory::getItem(int i)
{
    if(i > int(content.size()) || i< 0)
    {
        cout << "ERREUR : index inexistant" << endl;
        Item basic;
        return basic;
    }

    else
    {
        return content.at(unsigned (i));
    }
}

void Inventory::putItem(Item item)
{
    if(int(content.size()) >= max_size)
        cout << "ERREUR : inventaire plein";

    else
        content.push_back(item);
}
