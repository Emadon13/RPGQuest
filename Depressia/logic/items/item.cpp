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

std::string Item::use(Entity* target)
{
    return "vous venez d'utiliser un objet";
}
