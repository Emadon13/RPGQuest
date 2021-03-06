#include "enemyui.h"
#include <QProgressBar>

////////////////////////////////////////////////////////
///                                                  ///
///                   EnemyUI                        ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class EnemyUI

    Cette classe
*/

EnemyUI::EnemyUI(GameWindow *g, Mob *e, int x, int y, int width, int height) : QObject()
{
    game=g;
    posX=x;
    posY=y;
    perso=e;

    this->height=height;
    this->width=width;

    int imageWidht=int(width*0.85);
    int imageHeight=int(height*0.85);

    int nameWidth=imageWidht/2;
    int nameHeight=25;

    QString styleHP = "QProgressBar {border: 2px solid black; border-radius: 5px; background-color: #2d2d2d;} QProgressBar::chunk {background-color: #3df920;}";
    QString styleGlobal = "QLabel { color: #ffffff; background-color : #2d2d2d; border: 2px solid black; border-radius: 5px;}";

    boostAttack = new QLabel(game);
    boostAttack->setFixedSize((width-imageWidht),imageHeight/3);
    boostAttack->move(posX,posY);
    boostAttack->show();
    boostAttack->setStyleSheet(styleGlobal);

    boostDefense = new QLabel(game);
    boostDefense->setFixedSize((width-imageWidht),imageHeight/3);
    boostDefense->move(posX,posY+boostAttack->height());
    boostDefense->show();
    boostDefense->setStyleSheet(styleGlobal);

    boostSpeed = new QLabel(game);
    boostSpeed->setFixedSize((width-imageWidht),imageHeight/3);
    boostSpeed->move(posX,posY+boostAttack->height()+boostDefense->height());
    boostSpeed->show();
    boostSpeed->setStyleSheet(styleGlobal);

    image = new QLabel(game);
    image->setPixmap(perso->getBattleIcon()->scaled(imageWidht,imageHeight));
    image->setFixedSize(imageWidht,imageHeight);
    image->move(posX+boostAttack->width(),posY);
    image->show();

    name = new QLabel(game);
    name->setText(QString::fromStdString(perso->getName()));
    name->setAlignment(Qt::AlignCenter);
    name->setFixedSize(nameWidth,nameHeight);
    name->move(posX+boostAttack->width(),posY);
    name->show();
    name->setStyleSheet(styleGlobal);

    level = new QLabel(game);
    level->setText(QString::fromStdString(std::to_string(perso->getLvl())));
    level->setAlignment(Qt::AlignCenter);
    level->setFixedSize(width-imageWidht,height-imageHeight);
    level->move(posX,posY+imageHeight);
    level->show();
    level->setStyleSheet(styleGlobal);
    level->setWordWrap(true);

    jaugeHP = new QProgressBar(game);
    jaugeHP->setMaximum(perso->getHpMax());
    jaugeHP->setMinimum(0);
    jaugeHP->setFixedSize(imageWidht,(height-imageHeight));
    jaugeHP->move(posX+level->width(),posY+imageHeight);
    jaugeHP->show();
    jaugeHP->setValue(perso->getHp());
    jaugeHP->setFormat("");
    jaugeHP->setAlignment(Qt::AlignCenter);
    jaugeHP->setStyleSheet(styleHP);
}

void EnemyUI::Update()
{
    jaugeHP->setValue(perso->getHp());
}

