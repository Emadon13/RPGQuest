#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include "logic/world/map.h"
#include "gui/window/gamewindow.h"
#include <QPushButton>

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    SettingsWindow(GameWindow *g, QWidget *parent = nullptr);

private:
    QPalette *p;
    QPushButton *ok;
    QPushButton *quit;
};

#endif // ITEMWINDOW_H
