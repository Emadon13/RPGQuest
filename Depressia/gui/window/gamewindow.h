#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <vector>
#include "logic/game.h"
#include "logic/world/map.h"
#include "logic/world/mapelement.h"
#include "gui/clickable/clickablelabel.h"

using namespace std;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(Game *g, QWidget *parent = nullptr);
    ~GameWindow();

    void ClearWidget();
    Map* GetMap();
    Game* GetGame();

    void openCharacterWindow(Hero *allie);

public slots:
    void ShowFrame();
    void CreateBattleFrame();
    void CreateGameFrame();
    void CreateDialogFrame();
    void CreateVideoFrame();
    void CreateFinalFrame();
    void CreateAddHeroFrame();
    void CreateSaveFrame();
    void CreateGameOverFrame();
    void CreateItemFrame();
    void GoUp();
    void GoDown();
    void GoRight();
    void GoLeft();
    void afficheSave();
    void afficheItem();
    void afficheItemList();
    void afficheParametre();
    void resetFocus();
    void setPositionAfterLoose();
    void makeSave();
    void healTeam();

private:
    int WindowWidth;
    int WindowHeight;

    Game *game;

    Event *event;

    Map *map;

    MapElement mapElement;

    QPalette *p;
};

#endif // GAMEWINDOW_H
