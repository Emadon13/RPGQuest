#ifndef GAME_H
#define GAME_H

#include"io/maploader.h"


class Game
{
public:
    Game();
    Map* getMap();

    int getWindowHeight();
    int getWindowWidth();
    double getRatio();

    void setWindowHeight(int i);
    void setWindowWidth(int i);
    void setRatio(double l);


private:
    Map map;
    int windowHeight;
    int windowWidth;
    double ratio;

};

#endif // GAME_H
