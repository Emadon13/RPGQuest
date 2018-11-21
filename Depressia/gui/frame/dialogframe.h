#ifndef DIALOGFRAME_H
#define DIALOGFRAME_H
#include "gui/window/gamewindow.h"
#include "gui/clickable/clickablelabel.h"
#include"io/dialogloader.h"


class DialogFrame : QObject
{
    Q_OBJECT

public slots:
    void UpdateDialog();

public:
    DialogFrame(GameWindow *g);

    Map *map;

    MapElement mapElement;

    GameWindow *game;

    int currentPhase;
    vector<Dialog> tableau;

    QLabel *image;
    QLabel *dialogImage;
    QLabel *dialogText;
    ClickableLabel *clicker;

    vector<Dialog> getDialog();
};

#endif // DIALOGFRAME_H
