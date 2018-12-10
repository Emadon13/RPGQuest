#include "game.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <time.h>

using namespace std;

Game::Game():
    windowHeight(1080),
    windowWidth(1920),
    ratio(1.0),
    savePath("../ressources/save/save.vincent"),
    team(Team())
{
    map = MapLoader::generate(&team, "../ressources/maps/map.txt");
    srand (unsigned(time(nullptr)));
}

Map* Game::getMap()
{
    return &map;
}

int Game::getWindowHeight()
{
    return windowHeight;
}

int Game::getWindowWidth()
{
    return windowWidth;
}

double Game::getRatio()
{
    return ratio;
}

void Game::setWindowHeight(int i)
{
    if(i!=1080 && i!=720 && i!=768)
        cout << "ERREUR : windowHeight invalide" << endl;

    else
        windowHeight = i;
}

void Game::setWindowWidth(int i)
{
    if(i!=1920 && i!=1280 && i!= 1366)
        cout << "ERREUR : windowWidth invalide" << endl;

    else
        windowWidth = i;
}

void Game::setRatio(double l)
{
    if(l!=1.0 && l!=1.5 && l!=1.406)
        cout << "ERREUR : windowWidth invalide" << endl;

    else
        ratio = l;
}

void Game::save()
{

}

void Game::load()
{

}

Team* Game::getTeam()
{
    return &team;
}

