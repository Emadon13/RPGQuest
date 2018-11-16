#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>

class Item
{
public:
    Item();
    Item(std::string n, std::string d, std::string i);

    std::string getName();
    std::string getDescription();
    std::string getIcon();
    void use();


private:
    std::string name;
    std::string description;
    std::string icon;
};

#endif // ITEM_H
