#ifndef WINDOW_H
#define WINDOW_H

#include<string>

class Window
{
public:
    Window();
    Window(std::string ti, std::string te, std::string img);

    std::string getTitle();
    void getOption();

    Window* getLeft();
    Window* getUp();
    Window* getRight();
    Window* getDown();

    void setLeft(Window& w);
    void setUp(Window& w);
    void setRight(Window& w);
    void setDown(Window& w);

private:
    std::string title;
    std::string text;
    std::string background;

    Window *links[4];
};

#endif // WINDOW_H
