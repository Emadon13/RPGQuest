#include "dialogframe.h"
#include "gui/window/gamewindow.h"
#include "gui/window/mainwindow.h"
#include"io/dialogloader.h"
#include "gui/clickable/clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>

DialogFrame::DialogFrame(GameWindow *g) : QObject()
{
    game=g;
    map=game->GetMap();

    tableau=getDialog();

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio = game->GetGame()->getRatio();

    int DialogWidth(int(800/ratio));
    int DialogHeight(int(400/ratio));

    int ImageWidth(int(600/ratio));
    int ImageHeight(int(800/ratio));

    image = new QLabel(game);
    //image->setPixmap(QPixmap(QString::fromStdString(tableau.at(0).getElement(currentPhase).getImage())));
    image->setFixedSize(ImageWidth,ImageHeight);
    image->setAlignment(Qt::AlignCenter);

    dialogImage = new QLabel(game);
    dialogImage->setPixmap(QPixmap("../ressources/images/dialog.png").scaled(DialogWidth,DialogHeight));
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

    Dialog dial = *(dynamic_cast<Dialog*> (map->getCurrentPosition().getEvent()));  // J'ai changé un peu le contenu de ça
    vector<Dialog> dials;
    dials.push_back(dial);

    return dials;
}

void DialogFrame::UpdateDialog()
{
    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio = game->GetGame()->getRatio();

    int DialogWidth(int(800/ratio));
    int DialogHeight(int(400/ratio));

    int ImageWidth(int(600/ratio));
    int ImageHeight(int(800/ratio));

    int Espacement(int(100/ratio));

    if((currentPhase) >= int(tableau.at(0).getSize())){
        game->CreateGameFrame();
    }
    else{

        image->setPixmap(QPixmap(QString::fromStdString(tableau.at(0).getElement(currentPhase).getImage())).scaled(ImageWidth,ImageHeight));
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
