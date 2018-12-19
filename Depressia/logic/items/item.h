#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
#include "logic/entities/entity.h"

class Item
{
public:
    Item();
    Item(std::string n, std::string d, std::string i);

    std::string getName();
    std::string getText();
    std::string getImage();
    virtual std::string use(Entity* target);


private:
    std::string name;
    std::string text;
    std::string image;
};

#endif // ITEM_H
