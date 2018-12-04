#include "game.h"
#include <QFile>
#include <QDebug>
#include <QString>

using namespace std;

Game::Game():
    windowHeight(1080),
    windowWidth(1920),
    ratio(1.0),
    savePath("../ressources/save/save.vincent")
{
    map = MapLoader::generate("../ressources/maps/map.txt");
    //team[0] = new Entity("Bonasse", 1, 10, 5, 3, 2, 2, vector<Skill*>(0));
    //team[1] = new Entity("Rozalin", 10, 100, 50, 3, 2, 2, vector<Skill*>(0));
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


