#include "itemchoicewindow.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   ItemChoiceWindow               ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class ItemChoiceWindow

    Cette classe
*/


ItemChoiceWindow::ItemChoiceWindow(GameWindow *game, QWidget *parent) :
    QMainWindow(parent)
{
    gameWindow=game;
    this->game=game->GetGame();
    inventory=this->game->getTeam()->getInventory();

    QString styleBouton = "QPushButton {color:white; background-color: #302514;"
                          "border-style: outset; border-width: 2px;"
                          "border-radius: 10px; border-color: beige;"
                          "font: bold 14px; min-width: 10em; padding: 6px;}"
                          "QPushButton:pressed {color:white; background-color: #000000;"
                          "border-style: inset;}";

    int WindowWidth(800);
    int WindowHeight(400);

    int BoutonWidth(100);
    int BoutonHeight(60);

    int TitreWidth(400);
    int TitreHeight(50);

    int InfoWidth(460);
    int InfoHeight(200);

    ImageWidth=250;
    ImageHeight=250;

    int espacement(30);

    setWindowTitle("Use Item");
    setWindowIcon(QIcon("../ressources/images/hud/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    setCursor(Qt::CrossCursor);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap("../ressources/images/hud/itemBackground-1.png").scaled(WindowWidth,WindowHeight));
    background->setFixedSize(WindowWidth,WindowHeight);
    background->move(0,0);
    background->show();

    ok = new QPushButton("Utiliser", this);
    ok->setFixedSize(BoutonWidth,BoutonHeight);
    ok->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    ok->move((WindowWidth-BoutonWidth)/2+espacement+BoutonWidth,(WindowHeight-espacement-BoutonHeight));
    ok->setStyleSheet(styleBouton);
    ok->hide();

    retour = new QPushButton("Retour", this);
    retour->setFixedSize(BoutonWidth,BoutonHeight);
    retour->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    retour->move((WindowWidth-BoutonWidth)/2,(WindowHeight-espacement-BoutonHeight));
    retour->setStyleSheet(styleBouton);
    retour->hide();

    image = new QLabel(this);
    image->setFixedSize(ImageWidth,ImageHeight);
    image->move(espacement,(WindowHeight-ImageHeight)/2);
    image->hide();

    titre = new QLabel(this);
    titre->setFixedSize(TitreWidth,TitreHeight);
    titre->setAlignment(Qt::AlignCenter);
    titre->setWordWrap(true);
    titre->setText("Objets");
    titre->move(WindowWidth/2-espacement*3,0);
    titre->setStyleSheet("QLabel{color:white;}");
    titre->show();

    info = new QLabel(this);
    info->setFixedSize(InfoWidth,InfoHeight);
    info->setAlignment(Qt::AlignCenter);
    info->move(espacement*2+ImageWidth,espacement+TitreHeight);
    info->setWordWrap(true);
    info->hide();

    signalMapperObjet = new QSignalMapper(this);
    QObject::connect(signalMapperObjet, SIGNAL(mapped(int)), this, SLOT(choixObjet(int)));

    int espacementBouton(50);
    int boutonObjetWidth(100);
    int boutonObjetHeight((WindowHeight-espacementBouton*5)/4);

    for (int i = 0; i < 8; i=i+1)
    {
        selectionObjet[i] = new QPushButton("objet",this);
        selectionObjet[i]->setFixedSize(boutonObjetWidth,boutonObjetHeight);
        selectionObjet[i]->setStyleSheet(styleBouton);
        signalMapperObjet->setMapping(selectionObjet[i], i);
        connect(selectionObjet[i], SIGNAL(clicked()), signalMapperObjet, SLOT(map()));

        if(i<4)
        {
            selectionObjet[i]->move(WindowWidth/4-espacementBouton-boutonObjetWidth/2,espacementBouton*(i+1)+boutonObjetHeight*i);
            selectionObjet[i]->hide();
        }
        else
        {
            selectionObjet[i]->move((WindowWidth/2+espacementBouton),espacementBouton*(i-4+1)+boutonObjetHeight*(i-4));
            selectionObjet[i]->hide();
        }
    }

    signalMapperEntity = new QSignalMapper(this);
    QObject::connect(signalMapperEntity, SIGNAL(mapped(int)), this, SLOT(choixEntity(int)));

    for (int i=0 ; i < 4 ; i=i+1)
    {
        selectionEntity[i] = new QPushButton("Entity",this);
        selectionEntity[i]->setFixedSize(boutonObjetWidth,boutonObjetHeight);
        selectionEntity[i]->setStyleSheet(styleBouton);
        signalMapperEntity->setMapping(selectionEntity[i], i);
        connect(selectionEntity[i], SIGNAL(clicked()), signalMapperEntity, SLOT(map()));

        if(i<2)
        {
            selectionEntity[i]->move(WindowWidth/4-espacementBouton-boutonObjetWidth/2,((i+1)*3)*WindowHeight/4-boutonObjetHeight/4);
        }
        else
        {
            selectionEntity[i]->move((WindowWidth/2+espacementBouton),((i-2+1)*3)*WindowHeight/4-boutonObjetHeight/4);
        }
    }

    showItemList();
}

void ItemChoiceWindow::showItemList()
{
    for (int i = 0; i<inventory->getSize(); i=i+1)
    {
        selectionObjet[i]->setText(QString::fromStdString(inventory->getItem(i)->getName()));
        selectionObjet[i]->show();
    }

    image->hide();
    info->hide();

    for (int i = 0; i<4; i=i+1)
    {
        selectionEntity[i]->hide();
    }

    ok->hide();
    retour->show();
    QObject::connect(retour, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(retour, SIGNAL(clicked()), gameWindow, SLOT(resetFocus()));
}

void ItemChoiceWindow::choixObjet(int i)
{
    for (int i = 0; i<inventory->getSize(); i=i+1)
    {
        selectionObjet[i]->hide();
    }

    itemNumber=i;

    image->setPixmap(QPixmap(QString::fromStdString(inventory->getItem(i)->getImage())).scaled(ImageWidth,ImageHeight));
    image->show();
    titre->setText(QString::fromStdString(inventory->getItem(i)->getName()));
    info->setText(QString::fromStdString(inventory->getItem(i)->getText()));
    info->show();

    ok->show();
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(showEntityList()));
    QObject::connect(retour, SIGNAL(clicked()), this, SLOT(showItemList()));
    QObject::disconnect(retour, SIGNAL(clicked()), this, SLOT(close()));
    QObject::disconnect(retour, SIGNAL(clicked()), gameWindow, SLOT(resetFocus()));
}

void ItemChoiceWindow::showEntityList()
{
    for (int i = 0; i<4; i=i+1)
    {
        if(game->getTeam()->getHero(i)!=nullptr)
        {
            selectionEntity[i]->setText(QString::fromStdString(game->getTeam()->getHero(i)->getName()));
            selectionEntity[i]->show();
        }
    }

    image->hide();
    info->hide();

    for (int i = 0; i<8; i=i+1)
    {
        selectionObjet[i]->hide();
    }

    ok->hide();
    retour->show();
}

void ItemChoiceWindow::choixEntity(int i)
{
    for (int i = 0; i<4; i=i+1)
    {
        selectionEntity[i]->hide();
    }
    info->setText(QString::fromStdString(inventory->useItem(game->getTeam()->getHero(i),itemNumber)));
    info->show();
}
