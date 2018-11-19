#include "item.h"

using namespace std;

Item::Item():
    name("objet_nul"),
    text("aussi utile qu'une trempette stabbée sans z move"),
    image("")
{

}

Item::Item(string n, string d, string i):
    name(n),
    text(d),
    image(i)
{

}

string Item::getName()
{
    return name;
}

string Item::getText()
{
    return text;
}

string Item::getImage()
{
    return image;
}

void Item::use()
{
    cout << "vous venez d'utiliser un" << name <<"." << endl;
}
