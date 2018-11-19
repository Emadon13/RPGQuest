#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H
#include "gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>


class BattleFrame : QObject
{
    Q_OBJECT

public:
    BattleFrame(GameWindow *game,MapElement mapElement);

    GameWindow *game;
};

#endif // BATTLEFRAME_H
