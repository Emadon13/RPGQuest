#include "gameframe.h"
#include "gui/window/gamewindow.h"
#include "gui/window/mainwindow.h"
#include "logic/world/mapelement.h"
#include "gui/clickable/clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>
#include "gui/sprite.h"

GameFrame::GameFrame(GameWindow *g)
{
    game=g;
    map=g->GetMap();

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio(game->GetGame()->getRatio());

    int BoutonWidth(int(96/ratio));
    int BoutonHeight(int(96/ratio));
    int BoutonMarge(int(100/ratio));

    int InfoWidth(int(750/ratio));
    int InfoHeight(int(200/ratio));

    int TitleWidth(int(500/ratio));
    int TitleHeight(int(100/ratio));


    QGraphicsScene *scene = new QGraphicsScene(game);
    QGraphicsView *graphicsView = new QGraphicsView(game);
    Sprite *sprite = new Sprite();
    Sprite *sprite2 = new Sprite();

    graphicsView->setScene(scene);
    scene->addItem(sprite);
    scene->addItem(sprite2);

    graphicsView->setScene(scene);
    graphicsView->show();
    graphicsView->move(0,0);
    graphicsView->setStyleSheet("background-color: transparent;");
    graphicsView->setFrameStyle(QFrame::NoFrame);
    graphicsView->setFixedSize(WindowWidth,WindowHeight);

    sprite->setPos(QPointF(500,500));
    sprite2->setPos(QPointF(1500,200));
    sprite2->setRotation(45);
    scene->setSceneRect(0, 0, 1920, 1080);


    if(map->existUp())
    {
    ClickableLabel *boutonHaut = new ClickableLabel(game);
    boutonHaut->setPixmap(QPixmap("../ressources/images/fleche-haut.png").scaled(BoutonWidth,BoutonHeight));
    boutonHaut->setFixedSize(BoutonWidth,BoutonHeight);
    boutonHaut->installEventFilter(game);
    boutonHaut->move((WindowWidth-BoutonWidth)/2,BoutonMarge);
    boutonHaut->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonHaut->show();

    QObject::connect(boutonHaut, SIGNAL(clicked()), game, SLOT(GoUp()));
    }

    if(map->existDown())
    {
    ClickableLabel *boutonBas = new ClickableLabel(game);
    boutonBas->setPixmap(QPixmap("../ressources/images/fleche-bas.png").scaled(BoutonWidth,BoutonHeight));
    boutonBas->setFixedSize(BoutonWidth,BoutonHeight);
    boutonBas->installEventFilter(game);
    boutonBas->move((WindowWidth-BoutonWidth)/2,(WindowHeight-BoutonHeight-BoutonMarge));
    boutonBas->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonBas->show();

    QObject::connect(boutonBas, SIGNAL(clicked()), game, SLOT(GoDown()));
    }

    if(map->existRight())
    {
    ClickableLabel *boutonDroite = new ClickableLabel(game);
    boutonDroite->setPixmap(QPixmap("../ressources/images/fleche-droite.png").scaled(BoutonWidth,BoutonHeight));
    boutonDroite->setFixedSize(BoutonWidth,BoutonHeight);
    boutonDroite->installEventFilter(game);
    boutonDroite->move((WindowWidth-BoutonWidth-BoutonMarge),(WindowHeight-BoutonHeight)/2);
    boutonDroite->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonDroite->show();

    QObject::connect(boutonDroite, SIGNAL(clicked()), game, SLOT(GoRight()));
    }

    if(map->existLeft())
    {
    ClickableLabel *boutonGauche = new ClickableLabel(game);
    boutonGauche->setPixmap(QPixmap("../ressources/images/fleche-gauche.png").scaled(BoutonWidth,BoutonHeight));
    boutonGauche->setFixedSize(BoutonWidth,BoutonHeight);
    boutonGauche->installEventFilter(game);
    boutonGauche->move(BoutonMarge,(WindowHeight-BoutonHeight)/2);
    boutonGauche->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonGauche->show();

    QObject::connect(boutonGauche, SIGNAL(clicked()), game, SLOT(GoLeft()));
    }

    ClickableLabel *teamInfo = new ClickableLabel(game);
    teamInfo->setPixmap(QPixmap("../ressources/images/info-box.png").scaled(InfoWidth,InfoHeight));
    teamInfo->setFixedSize(InfoWidth,InfoHeight);
    teamInfo->installEventFilter(game);
    teamInfo->move(WindowWidth-InfoWidth,0);
    teamInfo->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    teamInfo->show();

    QLabel *zoneInfoImage = new QLabel(game);
    zoneInfoImage->setPixmap(QPixmap("../ressources/images/info-box.png").scaled(InfoWidth,InfoHeight));
    zoneInfoImage->setFixedSize(InfoWidth,InfoHeight);
    zoneInfoImage->move(0,0);
    zoneInfoImage->show();
    QLabel *zoneInfoText = new QLabel(game);
    zoneInfoText->setFixedSize(InfoWidth,InfoHeight);
    zoneInfoText->setText(QString::fromStdString(map->getCurrentPosition().getText()));
    zoneInfoText->setAlignment(Qt::AlignCenter);
    zoneInfoText->move(0,0);
    zoneInfoText->show();

    QLabel *zoneTitleImage = new QLabel(game);
    zoneTitleImage->setPixmap(QPixmap("../ressources/images/dialog-box.png").scaled(TitleWidth,TitleHeight));
    zoneTitleImage->setFixedSize(TitleWidth,TitleHeight);
    zoneTitleImage->move(0,WindowHeight-TitleHeight);
    zoneTitleImage->show();
    QLabel *zoneTitleText = new QLabel(game);
    zoneTitleText->setFixedSize(TitleWidth,TitleHeight);
    zoneTitleText->setText(QString::fromStdString(map->getCurrentPosition().getName()));
    zoneTitleText->setAlignment(Qt::AlignCenter);
    zoneTitleText->move(0,WindowHeight-TitleHeight);
    zoneTitleText->show();

}

