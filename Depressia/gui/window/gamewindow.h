#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <vector>
#include "logic/world/map.h"
#include "logic/world/mapelement.h"

using namespace std;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(Map *m, QWidget *parent = nullptr);
    ~GameWindow();

    void ClearWidget();
    Map* GetMap();

public slots:
    void ShowFrame();
    void CreateBattleFrame();
    void CreateGameFrame();
    void CreateDialogFrame();
    void CreateVideoFrame();
    void CreateItemFrame();
    void GoUp();
    void GoDown();
    void GoRight();
    void GoLeft();
    void afficheItem();

private:
    Map *map;

    MapElement mapElement;

    QPalette *p;
};

#endif // GAMEWINDOW_H
