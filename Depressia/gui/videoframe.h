#ifndef VIDEOFRAME_H
#define VIDEOFRAME_H
#include "gamewindow.h"
#include "clickablelabel.h"
#include "clikablevideowidget.h"
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
    ClikableVideoWidget *videoWidget;

    ClickableLabel *clicker;
};

#endif // VIDEOFRAME_H
