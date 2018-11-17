#ifndef DIALOGELEMENT_H
#define DIALOGELEMENT_H

#include<string>

enum Direction {direction_left, direction_right};

class DialogElement
{
public:
    DialogElement();
    DialogElement(Direction d, std::string n, std::string t, std::string i);

    Direction getDirection();
    std::string getName();
    std::string getText();
    std::string getImage();

private:
    Direction direction;
    std::string name;
    std::string text;
    std::string image;

};

#endif // DIALOGELEMENT_H
