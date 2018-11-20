#ifndef GAME_H
#define GAME_H

#include"io/maploader.h"


class Game
{
public:
    Game();
    Map getMap();

    int getWindowHeight();
    int getWindowWidth();
    float getRatio();

    void setWindowHeight(int i);
    void setWindowWidth(int i);
    void setRatio(long l);


private:
    Map map;
    int windowHeight;
    int windowWidth;
    long ratio;

};

#endif // GAME_H
