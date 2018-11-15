#include "window.h"
#include <iostream>

using namespace std;

Window::Window()
{
    title = "titre nul";
    text = "rien à dire...";
    background = "";

    Window *left(this);
    Window *up(this);
    Window *right(this);
    Window *down(this);

    links[0] = left;
    links[1] = up;
    links[2] = right;
    links[3] = down;
}

Window::Window(string ti, string te, string img)
{
    title = ti;
    text = te;
    background = img;

    Window *left(this);
    Window *up(this);
    Window *right(this);
    Window *down(this);

    links[0] = left;
    links[1] = up;
    links[2] = right;
    links[3] = down;
}

string Window::getTitle()
{
    return title;
}


Window* Window::getLeft()
{
    return links[0];
}

Window* Window::getUp()
{
    return links[1];
}

Window* Window::getRight()
{
    return links[2];
}

Window* Window::getDown()
{
    return links[3];
}

void Window::setLeft(Window& w)
{
    links[0] = &w;
}

void Window::setUp(Window& w)
{
    links[1] = &w;
}

void Window::setRight(Window& w)
{
    links[2] = &w;
}

void Window::setDown(Window& w)
{
    links[3] = &w;
}
