#ifndef DIALOG_H
#define DIALOG_H

#include<vector>
#include<iostream>
#include"logic/events/dialogelement.h"


class Dialog
{
public:
    Dialog();
    Dialog(std::vector<DialogElement> de);

    DialogElement getElement(int i);
    int getSize();

private:

    std::vector<DialogElement> elements;
};

#endif // DIALOG_H
