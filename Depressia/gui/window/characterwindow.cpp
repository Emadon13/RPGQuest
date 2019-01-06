#include "characterwindow.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   CharacterWindow                ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class CharacterWindow

    Cette classe
*/

CharacterWindow::CharacterWindow(GameWindow *game,Hero *allie, QWidget *parent) :
    QMainWindow(parent)
{
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

    int espacement=30;

    setWindowTitle("Stat");
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

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, WindowWidth, WindowHeight);

    view = new QGraphicsView(this);
    view->setScene(scene);
    view->show();
    view->move(0,0);
    view->setStyleSheet("background-color: transparent;");
    view->setFrameStyle(QFrame::NoFrame);
    view->setFixedSize(WindowWidth,WindowHeight);

    sprite=allie->getSpriteNormal();
    sprite->setPos(QPointF(espacement,(WindowHeight-ImageHeight)/2));
    sprite->show();
    scene->addItem(sprite);

    ok = new QPushButton("OK !", this);
    ok->setFixedSize(BoutonWidth,BoutonHeight);
    ok->move((WindowWidth-BoutonWidth)/2,(WindowHeight-espacement-BoutonHeight));
    ok->setStyleSheet(styleBouton);
    ok->show();
/*
    QLabel *image = new QLabel(this);
    image->setPixmap(allie->getBattleIcon()->scaled(ImageWidth,ImageHeight));
    image->setFixedSize(ImageWidth,ImageHeight);
    image->move(espacement,(WindowHeight-ImageHeight)/2);
    image->show();
*/
    QLabel *titre = new QLabel(this);
    titre->setText(QString::fromStdString(allie->getName()));
    titre->setFixedSize(TitreWidth,TitreHeight);
    titre->setAlignment(Qt::AlignCenter);
    titre->setWordWrap(true);
    titre->move(WindowWidth/2-espacement*3,0);
    titre->setStyleSheet("QLabel{color:white;}");
    titre->show();

    QLabel *info = new QLabel(this);
    info->setText(QString::fromStdString(+"NOM : "+allie->getName()+
                                         "\nNIV : "+std::to_string(allie->getLvl())+
                                         "\nEXP : "+std::to_string(allie->getXp())+
                                         "\nPV : "+std::to_string(allie->getHp())+"/"+std::to_string(allie->getHpMax())+
                                         "\nPM : "+std::to_string(allie->getMp())+"/"+std::to_string(allie->getMpMax())+
                                         "\nATK : "+std::to_string(allie->getAtt())+
                                         "\nDEF : "+std::to_string(allie->getDef())+
                                         "\nVIT : "+std::to_string(allie->getSpd())));

    info->setFixedSize(InfoWidth,InfoHeight);
    info->setAlignment(Qt::AlignCenter);
    info->move(espacement*2+ImageWidth,espacement+TitreHeight);
    info->setWordWrap(true);
    info->show();

    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ok, SIGNAL(clicked()), game, SLOT(resetFocus()));
}
