#include "videoframe.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gamewindow.h"
#include "mainwindow.h"

VideoFrame::VideoFrame(GameWindow *g, Map *m) : QObject()
{

    map=m;
    game=g;

    int WindowWidth(1920);
    int WindowHeight(1080);

    player = new QMediaPlayer(game);

    player->setMedia(QUrl(QUrl::fromLocalFile("../ressources/videos/trailer.wmv")));

    videoWidget = new QVideoWidget(game);
    player->setVideoOutput(videoWidget);

    clicker = new ClickableLabel(game);
    clicker->setFixedSize(WindowWidth,WindowHeight);
    clicker->move(0,0);
    clicker->show();

    videoWidget->setGeometry(0,0,WindowWidth,WindowHeight);
    videoWidget->showFullScreen();
    player->play();

    QObject::connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), game, SLOT(CreateGameFrame()));
    QObject::connect(clicker, SIGNAL(clicked()), game, SLOT(CreateGameFrame()));

}
