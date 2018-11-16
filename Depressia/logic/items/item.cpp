#include "item.h"

using namespace std;

Item::Item():
    name("objet_nul"),
    description("aussi utile qu'une trempette stabbée sans z move"),
    icon("")
{

}

Item::Item(string n, string d, string i):
    name(n),
    description(d),
    icon(i)
{

}

string Item::getName()
{
    return name;
}

string Item::getDescription()
{
    return description;
}

string Item::getIcon()
{
    return icon;
}

void Item::use()
{
    cout << "vous venez d'utiliser un" << name <<"." << endl;
}
