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
#include "gui/frame/characterui.h"
#include "gui/frame/enemyui.h"

BattleFrame::BattleFrame(GameWindow *g) : QObject()
{

    game=g;

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio(game->GetGame()->getRatio());

    scene = new QGraphicsScene(game);
    view = new QGraphicsView(game);
    sprite = new Sprite("../ressources/sprites/sprite_seraphina.png","../ressources/sprites/sprite_seraphina_damage.png","../ressources/sprites/sprite_seraphina_attack.png");
    sprite2 = new Sprite("../ressources/sprites/sprite_rozalin.png","../ressources/sprites/sprite_rozalin_damage.png","../ressources/sprites/sprite_rozalin_attack.png");

    view->setScene(scene);
    scene->addItem(sprite);
    scene->addItem(sprite2);

    view->setScene(scene);
    view->show();
    view->move(0,0);
    view->setStyleSheet("background-color: transparent;");
    view->setFrameStyle(QFrame::NoFrame);
    view->setFixedSize(WindowWidth,WindowHeight);

    sprite->setPos(QPointF(int(500/ratio),int(500/ratio)));
    sprite->setToolTip("Bonasse");

    sprite2->setPos(QPointF(int(1300/ratio),int(200/ratio)));

    scene->setSceneRect(0, 0, WindowWidth, WindowHeight);

    QPushButton *pass = new QPushButton("pass", game);
    pass->setFixedSize(100,100);
    pass->move(90,100);
    pass->show();
    QPushButton *damage = new QPushButton("damage", game);
    damage->setFixedSize(100,100);
    damage->move(200,100);
    damage->show();
    QPushButton *kill = new QPushButton("kill", game);
    kill->setFixedSize(100,100);
    kill->move(300,100);
    kill->show();
    QPushButton *attack = new QPushButton("attack", game);
    attack->setFixedSize(100,100);
    attack->move(400,100);
    attack->show();

    QObject::connect(pass, SIGNAL(clicked()), game , SLOT(ShowFrame()));

    QObject::connect(attack, SIGNAL(clicked()), this , SLOT(Attack()));
    QObject::connect(damage, SIGNAL(clicked()), this , SLOT(Damage()));
    QObject::connect(kill, SIGNAL(clicked()), this , SLOT(Kill()));

    int espacementUI=50;
    int tailleUI = int((game->GetGame()->getWindowHeight()-espacementUI*5)/4);

    CharacterUI *character1=new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI,tailleUI,tailleUI);
    CharacterUI *character2=new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*2+tailleUI,tailleUI,tailleUI);
    CharacterUI *character3=new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*3+tailleUI*2,tailleUI,tailleUI);
    CharacterUI *character4=new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*4+tailleUI*3,tailleUI,tailleUI);

    CharacterUI *enemy1 = new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI,tailleUI,tailleUI);
    CharacterUI *enemy1 = new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*2+tailleUI,tailleUI,tailleUI);
    CharacterUI *enemy1 = new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*3+tailleUI*2,tailleUI,tailleUI);
    CharacterUI *enemy1 = new CharacterUI(game,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*4+tailleUI*3,tailleUI,tailleUI);

}

void::BattleFrame::Attack()
{
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));

     QObject::disconnect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::connect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void::BattleFrame::Damage()
{
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));

     QObject::connect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void::BattleFrame::Kill()
{
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));


     QObject::disconnect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::connect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite2, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void BattleFrame::killEntity(Sprite *s)
{
    QObject::connect(s, SIGNAL(killed(Sprite*)), this , SLOT(deleteEntity(Sprite*)));
    s->kill();
}

void BattleFrame::damageEntity(Sprite *s)
{
    s->damage();
}

void BattleFrame::attackEntity(Sprite *s)
{
    s->attack();
}

void BattleFrame::deleteEntity(Sprite *s)
{
    scene->removeItem(s);
}



