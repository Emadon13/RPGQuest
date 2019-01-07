#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QMainWindow>
#include "logic/world/map.h"
#include "gui/window/gamewindow.h"
#include <QPushButton>

class SaveWindow : public QMainWindow
{
    Q_OBJECT

public:
    SaveWindow(GameWindow *g, QWidget *parent = nullptr);

private:
    QPalette *p;
    QPushButton *save;
    QPushButton *heal;
    QPushButton *quit;

};

#endif // SAVEWINDOW_H
