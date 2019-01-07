#include "videoframe.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gui/window/gamewindow.h"
#include "gui/window/mainwindow.h"
#include "logic/events/video.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   VideoFrame                     ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class VideoFrame

    Cette classe
*/

VideoFrame::VideoFrame(GameWindow *g) : QObject()
{

    game=g;
    map=game->GetMap();

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    player = new QMediaPlayer(game);

    player->setMedia(QUrl(QUrl::fromLocalFile(QString::fromStdString(dynamic_cast<Video*> (g->GetGame()->getMap()->getCurrentPosition().getEvent())->getVideo()))));

    videoWidget = new ClikableVideoWidget(game);
    player->setVideoOutput(videoWidget);

    videoWidget->setGeometry(0,0,WindowWidth,WindowHeight);
    videoWidget->showFullScreen();
    player->play();

    QObject::connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), game, SLOT(CreateGameFrame()));
    QObject::connect(videoWidget, SIGNAL(clicked()), player, SLOT(stop()));

}
