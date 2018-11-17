#ifndef DIALOG_H
#define DIALOG_H

#include<vector>
#include<iostream>
#include"logic/events/event.h"
#include"logic/events/dialogelement.h"


class Dialog : public Event
{
public:
    Dialog();
    Dialog(std::vector<DialogElement> de);
    DialogElement getElement(int i);

private:

    std::vector<DialogElement> elements;
};

#endif // DIALOG_H
