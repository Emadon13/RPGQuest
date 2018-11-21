#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H
#include "gui/window/gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>


class BattleFrame : QObject
{
    Q_OBJECT

public:
    BattleFrame(GameWindow *game);

    GameWindow *game;
};

#endif // BATTLEFRAME_H
