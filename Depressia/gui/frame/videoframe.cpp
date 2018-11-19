#include "videoframe.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gui/window/gamewindow.h"
#include "gui/window/mainwindow.h"

VideoFrame::VideoFrame(GameWindow *g, Map *m) : QObject()
{

    map=m;
    game=g;

    int WindowWidth(1920);
    int WindowHeight(1080);

    player = new QMediaPlayer(game);

    player->setMedia(QUrl(QUrl::fromLocalFile("../ressources/videos/trailer.wmv")));

    videoWidget = new ClikableVideoWidget(game);
    player->setVideoOutput(videoWidget);

    videoWidget->setGeometry(0,0,WindowWidth,WindowHeight);
    videoWidget->showFullScreen();
    player->play();

    QObject::connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), game, SLOT(CreateGameFrame()));
    QObject::connect(videoWidget, SIGNAL(clicked()), game, SLOT(CreateGameFrame()));

}
