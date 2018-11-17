#include "logic/events/dialogelement.h"

using namespace std;

DialogElement::DialogElement():
    direction(direction_left),
    name("Les développeurs"),
    text("Ce texte a été généré avec le constructeur par défaut. <br> Merci de votre compréhention."),
    image("")

{

}

DialogElement::DialogElement(Direction d, string n, string t, string i):
    direction(d),
    name(n),
    text(t),
    image(i)
{

}

Direction DialogElement::getDirection()
{
    return direction;
}

string DialogElement::getName()
{
    return name;
}

string DialogElement::getText()
{
    return text;
}

string DialogElement::getImage()
{
    return image;
}
