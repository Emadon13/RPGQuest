#include "gui/frame/battleframe.h"
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
#include "gui/clickable/clickablelabel.h"

BattleFrame::BattleFrame(GameWindow *g) : QObject()
{

    game=g;

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    scene = new QGraphicsScene(game);
    view = new QGraphicsView(game);
    sprite = new Sprite();
    sprite2 = new Sprite();

    view->setScene(scene);
    scene->addItem(sprite);
    scene->addItem(sprite2);

    view->setScene(scene);
    view->show();
    view->move(0,0);
    view->setStyleSheet("background-color: transparent;");
    view->setFrameStyle(QFrame::NoFrame);
    view->setFixedSize(WindowWidth,WindowHeight);

    sprite->setPos(QPointF(500,500));
    sprite->setToolTip("Bonasse");

    sprite2->setPos(QPointF(1500,200));

    scene->setSceneRect(0, 0, 1920, 1080);

    QPushButton *test = new QPushButton("attack", game);
    test->setFixedSize(100,100);
    test->move(800,800);
    test->show();

    QObject::connect(test, SIGNAL(clicked()), game , SLOT(ShowFrame()));

    QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
    QObject::connect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));

}


void BattleFrame::killEntity(Sprite *s)
{
    QObject::connect(s, SIGNAL(killed(Sprite*)), this , SLOT(deleteEntity(Sprite*)));
    s->kill();
}


void BattleFrame::deleteEntity(Sprite *s)
{
    s->deleteLater();
}



