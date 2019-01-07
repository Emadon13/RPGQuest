#ifndef ADDHEROFRAME_H
#define ADDHEROFRAME_H

#include "gui/window/gamewindow.h"
#include "gui/clickable/clickablelabel.h"
#include"io/dialogloader.h"

class AddHeroFrame : QObject
{
    Q_OBJECT

public slots:
    void UpdateDialog();

public:
    AddHeroFrame(GameWindow *g);

    Map *map;

    MapElement mapElement;

    GameWindow *game;

    int currentPhase;
    int espacementName;
    vector<Dialog> tableau;

    QLabel *image;
    QLabel *dialogImage;
    QLabel *dialogText;
    QLabel *dialogName;
    ClickableLabel *clicker;

    vector<Dialog> getDialog();
};

#endif // ADDHEROFRAME_H
