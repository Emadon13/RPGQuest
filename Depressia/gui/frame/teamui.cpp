#include "teamui.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   TeamUI                         ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class TeamUI

    Cette classe
*/

TeamUI::TeamUI(GameWindow *g, Hero *e, int x, int y, int width, int height) : QObject()
{
    game=g;
    posX=x;
    posY=y;
    perso=e;

    this->height=height;
    this->width=width;

    int imageWidht=int(width*0.8);
    int imageHeight=int(height*0.8);

    QString styleHP = "QProgressBar {border: 2px solid black; border-radius: 5px; background-color: #666666;} QProgressBar::chunk {background-color: #3df920;}";
    QString styleMP = "QProgressBar {border: 2px solid black; border-radius: 5px; background-color: #666666;} QProgressBar::chunk {background-color: #05B8CC;}";
    QString styleGlobal = "QLabel { color: #ffffff; background-color : #2d2d2d; border: 2px solid black; border-radius: 5px;}";

    image = new QLabel(game);
    image->setPixmap(perso->getBattleIcon()->scaled(imageWidht,imageHeight));
    image->setFixedSize(imageWidht,imageHeight);
    image->move(posX,posY);
    image->show();

    level = new QLabel(game);
    level->setText(QString::fromStdString(std::to_string(perso->getLvl())));
    level->setAlignment(Qt::AlignCenter);
    level->setFixedSize(width-imageWidht,height-imageHeight);
    level->move(posX+imageWidht,posY+imageHeight);
    level->show();
    level->setStyleSheet(styleGlobal);
    level->setWordWrap(true);

    jaugeHP = new QProgressBar(game);
    jaugeHP->setMaximum(perso->getHpMax());
    jaugeHP->setMinimum(0);
    jaugeHP->setFixedSize(imageWidht,height-imageHeight);
    jaugeHP->move(posX,posY+imageHeight);
    jaugeHP->show();
    jaugeHP->setValue(perso->getHp());
    jaugeHP->setAlignment(Qt::AlignCenter);
    jaugeHP->setStyleSheet(styleHP);
    jaugeHP->setFormat("");

    jaugeMP = new QProgressBar(game);
    jaugeMP->setMaximum(perso->getMpMax());
    jaugeMP->setMinimum(0);
    jaugeMP->setFixedSize(width-imageWidht,imageHeight);
    jaugeMP->move(posX+imageWidht,posY);
    jaugeMP->show();
    jaugeMP->setValue(perso->getMp());
    jaugeMP->setAlignment(Qt::AlignCenter);
    jaugeMP->setStyleSheet(styleMP);
    jaugeMP->setFormat("");

    clicker = new ClickableLabel(game);
    clicker->setFixedSize(width,height);
    clicker->move(x,y);
    clicker->show();

    QObject::connect(clicker, SIGNAL(clicked()),this,SLOT(openCharacterInfo()));
}

void TeamUI::Update()
{
    jaugeHP->setValue(perso->getHp());

    jaugeMP->setValue(perso->getMp());
}

void TeamUI::openCharacterInfo()
{
    game->openCharacterWindow(perso);
}
