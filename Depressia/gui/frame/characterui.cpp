#include "characterui.h"
#include <QProgressBar>

CharacterUI::CharacterUI(GameWindow *g, int x, int y, int width, int height) : QObject()
{
    game=g;
    posX=x;
    posY=y;

    this->height=height;
    this->width=width;

    int imageWidht=int(width*0.75);
    int imageHeight=int(height*0.75);

    int nameWidth=imageWidht/2;
    int nameHeight=25;

    QString styleHP = "QProgressBar {border: 2px solid black; border-radius: 5px; background-color: #666666;} QProgressBar::chunk {background-color: #3df920;}";
    QString styleMP = "QProgressBar {border: 2px solid black; border-radius: 5px; background-color: #666666;} QProgressBar::chunk {background-color: #05B8CC;}";
    QString styleEXP = "QProgressBar {border: 2px solid black; border-radius: 5px; background-color: #666666;} QProgressBar::chunk {background-color: #f9f920;}";
    QString styleGlobal = "QLabel { color: #ffffff; background-color : #2d2d2d; border: 2px solid black; border-radius: 5px;}";


    image = new QLabel(game);
    image->setPixmap(QPixmap(QString::fromStdString("../ressources/images/bonasse-icon.png")).scaled(imageWidht,imageHeight));
    image->setFixedSize(imageWidht,imageHeight);
    image->move(posX,posY);
    image->show();


    name = new QLabel(game);
    name->setText("Bonasse");
    name->setAlignment(Qt::AlignCenter);
    name->setFixedSize(nameWidth,nameHeight);
    name->move(posX+nameWidth,posY);
    name->show();
    name->setStyleSheet(styleGlobal);

    level = new QLabel(game);
    level->setText("NIV 10");
    level->setAlignment(Qt::AlignCenter);
    level->setFixedSize(width-imageWidht,height-imageHeight);
    level->move(posX+imageWidht,posY+imageHeight);
    level->show();
    level->setStyleSheet(styleGlobal);
    level->setWordWrap(true);

    jaugeHP = new QProgressBar(game);
    jaugeHP->setMaximum(25);
    jaugeHP->setMinimum(0);
    jaugeHP->setFixedSize(imageWidht,(height-imageHeight)/2);
    jaugeHP->move(posX,posY+imageHeight);
    jaugeHP->show();
    jaugeHP->setValue(20);
    jaugeHP->setFormat("PV : 20/25");
    jaugeHP->setAlignment(Qt::AlignCenter);
    jaugeHP->setStyleSheet(styleHP);

    jaugeMP = new QProgressBar(game);
    jaugeMP->setMaximum(12);
    jaugeMP->setMinimum(0);
    jaugeMP->setFixedSize(imageWidht,(height-imageHeight)/2);
    jaugeMP->move(posX,posY+imageHeight+jaugeHP->height());
    jaugeMP->show();
    jaugeMP->setValue(5);
    jaugeMP->setFormat("PM : 5/12");
    jaugeMP->setAlignment(Qt::AlignCenter);
    jaugeMP->setStyleSheet(styleMP);

    jaugeEXP = new QProgressBar(game);
    jaugeEXP->setMaximum(150);
    jaugeEXP->setMinimum(0);
    jaugeEXP->setFixedSize((width-imageWidht)/2,imageHeight);
    jaugeEXP->move(posX+imageWidht,posY);
    jaugeEXP->show();
    jaugeEXP->setValue(90);
    jaugeEXP->setFormat("XP");
    jaugeEXP->setAlignment(Qt::AlignCenter);
    jaugeEXP->setStyleSheet(styleEXP);
    jaugeEXP->setOrientation(Qt::Vertical);

    boostAttack = new QLabel(game);
    boostAttack->setFixedSize((width-imageWidht)/2,imageHeight/3);
    boostAttack->move(posX+imageWidht+jaugeEXP->width(),posY);
    boostAttack->show();
    boostAttack->setStyleSheet(styleGlobal);

    boostDefense = new QLabel(game);
    boostDefense->setFixedSize((width-imageWidht)/2,imageHeight/3);
    boostDefense->move(posX+imageWidht+jaugeEXP->width(),posY+boostAttack->height());
    boostDefense->show();
    boostDefense->setStyleSheet(styleGlobal);

    boostSpeed = new QLabel(game);
    boostSpeed->setFixedSize((width-imageWidht)/2,imageHeight/3);
    boostSpeed->move(posX+imageWidht+jaugeEXP->width(),posY+boostAttack->height()+boostDefense->height());
    boostSpeed->show();
    boostSpeed->setStyleSheet(styleGlobal);
}