#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QMainWindow>
#include "logic/world/map.h"
#include "gui/window/gamewindow.h"
#include <QPushButton>

class ItemWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void addItem();

public:
    ItemWindow(GameWindow *g, QWidget *parent = nullptr);

private:
    Game *game;

    QPalette *p;
    MapElement mapElement;
    Map *map;
    QPushButton *ok;
};

#endif // ITEMWINDOW_H
