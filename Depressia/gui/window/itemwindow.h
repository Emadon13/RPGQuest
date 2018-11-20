#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QMainWindow>
#include "logic/world/map.h"
#include <QPushButton>

class ItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    ItemWindow(Map *m, QWidget *parent = nullptr);

private:
    QPalette *p;
    MapElement mapElement;
    Map *map;
    QPushButton *ok;
};

#endif // ITEMWINDOW_H
