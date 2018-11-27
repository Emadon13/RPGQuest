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

    void save();
    Game* load();


private:
    Map map;
    int windowHeight;
    int windowWidth;
    double ratio;
    std::string savePath;

};

#endif // GAME_H
