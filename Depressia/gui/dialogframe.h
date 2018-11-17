#pragma once

#ifndef DIALOGFRAME_H
#define DIALOGFRAME_H
#include "gamewindow.h"
#include "clickablelabel.h"
#include"io/dialogloader.h"


class DialogFrame : QObject
{
    Q_OBJECT

public slots:
    void UpdateDialog();

public:
    DialogFrame(GameWindow *g);

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
