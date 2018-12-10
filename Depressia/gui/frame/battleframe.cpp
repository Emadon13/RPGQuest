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

    fight=((dynamic_cast<Fight*>(game->GetGame()->getMap()->getCurrentPosition().getEvent())));


    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio(game->GetGame()->getRatio());

    QLabel *back = new QLabel(game);
    back->setPixmap(QPixmap("../ressources/images/hud/background-battle4.png").scaled(WindowWidth,WindowHeight));
    back->setFixedSize(WindowWidth,WindowHeight);
    back->move(0,0);
    back->show();


    scene = new QGraphicsScene(game);
    scene->setSceneRect(0, 0, WindowWidth, WindowHeight);

    view = new QGraphicsView(game);
    view->setScene(scene);
    view->show();
    view->move(0,0);
    view->setStyleSheet("background-color: transparent;");
    view->setFrameStyle(QFrame::NoFrame);
    view->setFixedSize(WindowWidth,WindowHeight);


    int espacementUI=50;
    int tailleUI = int((game->GetGame()->getWindowHeight()-espacementUI*5)/4);


    for (int i=0; i<= Fight::nb_e; i=i+1)
    {
        allie = fight->getHeroes()[i];

        sprite = new Sprite(6,130,200,"../ressources/images/sprites/sprite_seraphina.png",0,0,0,"",0,0,0,"",0,0,0,"",0,0,0,"");
        sprite->setPos(QPointF(int((1300+i*50)/ratio),int(500/ratio)));
        sprite->setToolTip("Bonasse");

        teamSprite[i]=sprite;
        scene->addItem(teamSprite[i]);

        character = new CharacterUI(game,allie,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*(i+1)+tailleUI*i,tailleUI,tailleUI);
        teamUI[i]=character;
    }

    /*for (i=0; i<= taille ennemy team; i=i+1)
    {
    sprite = new Sprite(6,130,200,"../ressources/images/sprites/sprite_seraphina.png",0,0,0,"",0,0,0,"",0,0,0,"",0,0,0,"");
    scene->addItem(sprite);
    bonasse = game->GetGame()->team.getHero(0);
    sprite->setPos(QPointF(int(1300/ratio),int(500/ratio)));
    sprite->setToolTip("Bonasse");
    enemy = new EnemyUI(game,bonasse,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*2+tailleUI,tailleUI,tailleUI);
    //}
    }*/


    int dialogWidth(int(WindowWidth*0.4));
    int dialogHeight(int(WindowHeight*0.2));

    dialogInfo = new QLabel(game);
    dialogInfo->setPixmap(QPixmap("../ressources/images/hud/jaugeHP.png").scaled(dialogWidth,dialogHeight));
    dialogInfo->setFixedSize(dialogWidth,dialogHeight);
    dialogInfo->move(WindowWidth/2-dialogWidth/2,0);
    dialogInfo->show();

    QLabel *dialogSelection = new QLabel(game);
    dialogSelection->setPixmap(QPixmap("../ressources/images/hud/jaugeHP.png").scaled(dialogWidth,dialogHeight));
    dialogSelection->setFixedSize(dialogWidth,dialogHeight);
    dialogSelection->move(WindowWidth/2-dialogWidth/2,WindowHeight-dialogHeight);
    dialogSelection->show();


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
}

void::BattleFrame::Attack()
{
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void::BattleFrame::Damage()
{
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void::BattleFrame::Kill()
{
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void BattleFrame::killEntity(Sprite *s)
{
    QObject::connect(s, SIGNAL(killed(Sprite*)), this , SLOT(deleteEntity(Sprite*)));
    s->kill();
}

void BattleFrame::damageEntity(Sprite *s)
{

}

void BattleFrame::attackEntity(Sprite *s)
{
    std::string test;

    /*if(s->getEntity()==bonasse)
    {
        sprite->attack();
        sprite2->damage();
        test = bonasse->hitOpponent(*rozalin);
    }
    else
    {
        sprite2->attack();
        sprite->damage();
        test = rozalin->hitOpponent(*bonasse);
    }
    enemy->Update();
    character->Update();
    dialogInfo->setText(QString::fromStdString(test));*/
}

void BattleFrame::deleteEntity(Sprite *s)
{
    scene->removeItem(s);
}



