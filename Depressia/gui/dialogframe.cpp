#include "dialogframe.h"
#include "gamewindow.h"
#include "mainwindow.h"
#include"io/dialogloader.h"
#include "clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>

DialogFrame::DialogFrame(GameWindow *g, Map *m) : QObject()
{
    this->mapElement=mapElement;

    map=m;
    game=g;

    tableau=getDialog();

    int WindowWidth(1920);
    int WindowHeight(1080);

    int DialogWidth(800);
    int DialogHeight(400);

    int ImageWidth(600);
    int ImageHeight(800);

    image = new QLabel(game);
    //image->setPixmap(QPixmap(QString::fromStdString(tableau.at(0).getElement(currentPhase).getImage())));
    image->setFixedSize(ImageWidth,ImageHeight);
    image->setAlignment(Qt::AlignCenter);

    dialogImage = new QLabel(game);
    dialogImage->setPixmap(QPixmap("../ressources/images/dialog.png"));
    dialogImage->setFixedSize(DialogWidth,DialogHeight);

    dialogText = new QLabel(game);
    //dialogText->setText(QString::fromStdString((tableau.at(0).getElement(currentPhase).getName())+" : "+(tableau.at(0).getElement(currentPhase).getText())));
    dialogText->setFixedSize(DialogWidth,DialogHeight);
    dialogText->setAlignment(Qt::AlignCenter);

    clicker = new ClickableLabel(game);
    clicker->setFixedSize(WindowWidth,WindowHeight);
    clicker->move(0,0);

    currentPhase=0;

    UpdateDialog();

    QObject::connect(clicker, SIGNAL(clicked()), this, SLOT(UpdateDialog()));
}

vector<Dialog> DialogFrame::getDialog()
{

    Dialog dial = map->getCurrentPosition().getEvent().getDialog();  // J'ai changé un peu le contenu de ça
    vector<Dialog> dials;
    dials.push_back(dial);

    return dials;
}

void DialogFrame::UpdateDialog()
{
    int WindowWidth(1920);
    int WindowHeight(1080);

    int DialogWidth(800);
    int DialogHeight(400);

    int ImageWidth(600);
    int ImageHeight(800);

    int Espacement(100);

    if((currentPhase) >= int(tableau.at(0).getSize())){
        game->CreateGameFrame();
    }
    else{

        image->setPixmap(QPixmap(QString::fromStdString(tableau.at(0).getElement(currentPhase).getImage())));
        dialogText->setText(QString::fromStdString((tableau.at(0).getElement(currentPhase).getName())+" : "+(tableau.at(0).getElement(currentPhase).getText())));

        if((tableau.at(0).getElement(currentPhase).getDirection())==direction_right){

            image->move(WindowWidth-ImageWidth-Espacement,WindowHeight-ImageHeight);
            image->show();

            dialogImage->move(Espacement,WindowHeight-DialogHeight-Espacement);
            dialogImage->show();
            dialogText->move(Espacement,WindowHeight-DialogHeight-Espacement);
            dialogText->show();

            clicker->show();

        }
        else{

            image->move(Espacement,WindowHeight-ImageHeight);
            image->show();

            dialogImage->move(WindowWidth-DialogWidth-Espacement,WindowHeight-DialogHeight-Espacement);
            dialogImage->show();
            dialogText->move(WindowWidth-DialogWidth-Espacement,WindowHeight-DialogHeight-Espacement);
            dialogText->show();

            clicker->show();

        }
    }
    currentPhase=currentPhase+1;
}
