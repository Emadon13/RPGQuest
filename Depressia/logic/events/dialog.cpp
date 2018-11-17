#include "dialog.h"

using namespace std;

Dialog::Dialog():
    elements(0)
{
    DialogElement de;
    elements.push_back(de);
    eventType = dialog;
}

Dialog::Dialog(vector<DialogElement> de):
    elements(de)
{
    eventType =dialog;
}

DialogElement Dialog::getElement(int i)
{
    if (i >= int(elements.size()) || i< 0)
    {
        cout << "ERREUR : index supérieur à la taille du dialogue" << endl;
        DialogElement de;
        return de;
    }

    else
        return elements.at(unsigned(i));
}
