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

    int ImageWidth(250);
    int ImageHeight(250);

    int espacement(30);
    int espacementBouton(50);

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
    ok->move((WindowWidth-BoutonWidth)/2,(WindowHeight-espacement-BoutonHeight));
    ok->setStyleSheet(styleBouton);
    ok->hide();

    retour = new QPushButton("retour", this);
    retour->setFixedSize(BoutonWidth,BoutonHeight);
    retour->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    retour->move((WindowWidth-BoutonWidth)/2,(WindowHeight-espacement-BoutonHeight));
    retour->setStyleSheet(styleBouton);
    retour->hide();

    QLabel *image = new QLabel(this);
    image->setFixedSize(ImageWidth,ImageHeight);
    image->move(espacement,(WindowHeight-ImageHeight)/2);
    image->hide();

    QLabel *titre = new QLabel(this);
    titre->setFixedSize(TitreWidth,TitreHeight);
    titre->setAlignment(Qt::AlignCenter);
    titre->setWordWrap(true);
    titre->move(WindowWidth/2-espacement*3,0);
    titre->setStyleSheet("QLabel{color:white;}");
    titre->hide();

    QLabel *info = new QLabel(this);
    info->setFixedSize(InfoWidth,InfoHeight);
    info->setAlignment(Qt::AlignCenter);
    info->move(espacement*2+ImageWidth,espacement+TitreHeight);
    info->setWordWrap(true);
    info->hide();

    QObject::connect(retour, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(retour, SIGNAL(clicked()), game, SLOT(resetFocus()));
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(useItem()));

    signalMapperObjet = new QSignalMapper(this);
    QObject::connect(signalMapperObjet, SIGNAL(mapped(int)), this, SLOT(choixObjet(int)));

    /*for (int i = 0; i < 8; i=i+1)
    {
        selectionObjet[i] = new QPushButton("objet",game);
        selectionObjet[i]->setFixedSize(boutonWidth,int(boutonHeight*0.5));
        selectionObjet[i]->setStyleSheet(styleBouton);
        signalMapperObjet->setMapping(selectionObjet[i], i);
        connect(selectionObjet[i], SIGNAL(clicked()), signalMapperObjet, SLOT(map()));

        if(i<4)
        {
            selectionObjet[i]->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonVChoix*(i+1)+int(boutonHeight*0.5*i));
        }
        else
        {
            selectionObjet[i]->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonVChoix*(i-4+1)+int(boutonHeight*0.5*(i-4)));
        }
    }

    signalMapperEntity = new QSignalMapper(this);
    QObject::connect(signalMapperEntity, SIGNAL(mapped(int)), this, SLOT(choixEntity(int)));

    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        selectionEntity[i] = new QPushButton("Entity",game);
        selectionEntity[i]->setFixedSize(boutonWidth,boutonHeight);
        selectionEntity[i]->setStyleSheet(styleBouton);
        signalMapperEntity->setMapping(selectionEntity[i], i);
        connect(selectionEntity[i], SIGNAL(clicked()), signalMapperEntity, SLOT(map()));

        if(i<2)
        {
            selectionEntity[i]->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonV*(i+1)+boutonHeight*i);
        }
        else
        {
            selectionEntity[i]->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonV*(2-i+1)+boutonHeight*(2-i));
        }
    }*/

    for (int i = 0; i<inventory->getSize(); i=i+1)
    {
        selectionObjet[i]->setText(QString::fromStdString(inventory->getItem(i).getName()));
        selectionObjet[i]->show();
    }
}
