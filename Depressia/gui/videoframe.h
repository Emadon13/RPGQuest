#ifndef VIDEOFRAME_H
#define VIDEOFRAME_H
#include "gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>


class VideoFrame : QObject
{
    Q_OBJECT

public:
    VideoFrame(GameWindow *game, Map *m);

    GameWindow *game;
    Map *map;

    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // VIDEOFRAME_H
