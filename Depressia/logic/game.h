#ifndef GAME_H
#define GAME_H

#include"io/maploader.h"
#include <QString>


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
    void load();


private:
    Map map;
    int windowHeight;
    int windowWidth;
    double ratio;
    QString savePath;

};

#endif // GAME_H
