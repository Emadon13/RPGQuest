#ifndef CHARACTERUI_H
#define CHARACTERUI_H
#include <QObject>
#include "gui/window/gamewindow.h"
#include <QProgressBar>

class CharacterUI: QObject
{
    Q_OBJECT

public slots:
    void Update();

public:
    CharacterUI(GameWindow *g, Hero *e, int x, int y, int width, int height);

    GameWindow *game;

    Hero *perso;

    int posX;
    int posY;

    int height;
    int width;

    QLabel *image;
    QLabel *name;
    QLabel *level;

    QProgressBar *jaugeHP;
    QProgressBar *jaugeMP;
    QProgressBar *jaugeEXP;

    QLabel *boostAttack;
    QLabel *boostDefense;
    QLabel *boostSpeed;

    ClickableLabel *clicker;
};

#endif // CHARACTERUI_H
