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
    std::string getText();
    std::string getImage();
    void use();


private:
    std::string name;
    std::string text;
    std::string image;
};

#endif // ITEM_H
