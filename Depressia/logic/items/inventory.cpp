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
        return ItemLoader::generate(content.at(unsigned (i)));
    }
}

void Inventory::putItem(string item)
{
    if(int(content.size()) >= max_size)
        cout << "ERREUR : inventaire plein";

    else
        content.push_back(item);
}

bool Inventory::isEmpty()
{
    return content.empty();
}

bool Inventory::isFull()
{
    return(content.size()>=max_size);
}

string Inventory::useItem(Entity* e, int i)
{
    string result = "L'index n'est pas bon !";

    if(i<max_size && i>=0)
    {
        ItemLoader::generate(content.at(unsigned(i))).use(e);
        result = ItemLoader::generate(content.at(unsigned(i))).getText();
        content.erase(content.begin() + i);
    }

    return result;
}
