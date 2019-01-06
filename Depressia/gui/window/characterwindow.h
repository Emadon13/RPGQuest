#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

#include "gui/window/gamewindow.h"
#include "QGraphicsScene"
#include "QGraphicsView"

class CharacterWindow : public QMainWindow
{
    Q_OBJECT

public:
    CharacterWindow(GameWindow *g, Hero *allie, QWidget *parent = nullptr);

private:
    QPalette *p;
    QPushButton *ok;

    SpriteTemplate *sprite;

    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // CHARACTERWINDOW_H
