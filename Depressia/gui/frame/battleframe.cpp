#include "battleframe.h"
#include "gui/window/gamewindow.h"
#include "gui/window/mainwindow.h"
#include "gui/clickable/clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <vector>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gui/sprite.h"

BattleFrame::BattleFrame(GameWindow *g) : QObject()
{

    game=g;

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    QGraphicsScene *scene = new QGraphicsScene(game);
    QGraphicsView *graphicsView = new QGraphicsView(game);
    Sprite *sprite = new Sprite();
    Sprite *sprite2 = new Sprite();

    graphicsView->setScene(scene);
    scene->addItem(sprite);
    scene->addItem(sprite2);

    graphicsView->setScene(scene);
    graphicsView->show();
    graphicsView->move(0,0);
    graphicsView->setStyleSheet("background-color: transparent;");
    graphicsView->setFrameStyle(QFrame::NoFrame);
    graphicsView->setFixedSize(WindowWidth,WindowHeight);

    sprite->setPos(QPointF(500,500));
    sprite->setToolTip("Bonasse");
    sprite2->setPos(QPointF(1500,200));
    scene->setSceneRect(0, 0, 1920, 1080);

}

