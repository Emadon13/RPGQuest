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

GameFrame::GameFrame(GameWindow *g)
{
    game=g;
    map=g->GetMap();

    QString styleBoutonRond = "QPushButton {color:white; background-color: #302514;"
                              "border-style: outset; border-width: 1px;"
                              "border-radius: 25px; border-color: beige;"
                              "font: bold 14px; padding: 6px;}"
                              "QPushButton:pressed {color:white; background-color: #000000;"
                              "border-style: inset;}";


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

    QLabel *back = new QLabel(game);
    back->setPixmap(QPixmap("../ressources/images/hud/background-game-3.png").scaled(WindowWidth,WindowHeight));
    back->setFixedSize(WindowWidth,WindowHeight);
    back->move(0,0);
    back->show();

    if(map->existUp())
    {
    ClickableLabel *boutonHaut = new ClickableLabel(game);
    boutonHaut->setPixmap(QPixmap("../ressources/images/hud/fleche-haut.png").scaled(BoutonWidth,BoutonHeight));
    boutonHaut->setFixedSize(BoutonWidth,BoutonHeight);
    boutonHaut->installEventFilter(game);
    boutonHaut->move((WindowWidth-BoutonWidth)/2,BoutonMarge);
    boutonHaut->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    boutonHaut->show();

    QObject::connect(boutonHaut, SIGNAL(clicked()), game, SLOT(GoUp()));
    }

    if(map->existDown())
    {
    ClickableLabel *boutonBas = new ClickableLabel(game);
    boutonBas->setPixmap(QPixmap("../ressources/images/hud/fleche-bas.png").scaled(BoutonWidth,BoutonHeight));
    boutonBas->setFixedSize(BoutonWidth,BoutonHeight);
    boutonBas->installEventFilter(game);
    boutonBas->move((WindowWidth-BoutonWidth)/2,(WindowHeight-BoutonHeight-BoutonMarge));
    boutonBas->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    boutonBas->show();

    QObject::connect(boutonBas, SIGNAL(clicked()), game, SLOT(GoDown()));
    }

    if(map->existRight())
    {
    ClickableLabel *boutonDroite = new ClickableLabel(game);
    boutonDroite->setPixmap(QPixmap("../ressources/images/hud/fleche-droite.png").scaled(BoutonWidth,BoutonHeight));
    boutonDroite->setFixedSize(BoutonWidth,BoutonHeight);
    boutonDroite->installEventFilter(game);
    boutonDroite->move((WindowWidth-BoutonWidth-BoutonMarge),(WindowHeight-BoutonHeight)/2);
    boutonDroite->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    boutonDroite->show();

    QObject::connect(boutonDroite, SIGNAL(clicked()), game, SLOT(GoRight()));
    }

    if(map->existLeft())
    {
    ClickableLabel *boutonGauche = new ClickableLabel(game);
    boutonGauche->setPixmap(QPixmap("../ressources/images/hud/fleche-gauche.png").scaled(BoutonWidth,BoutonHeight));
    boutonGauche->setFixedSize(BoutonWidth,BoutonHeight);
    boutonGauche->installEventFilter(game);
    boutonGauche->move(BoutonMarge,(WindowHeight-BoutonHeight)/2);
    boutonGauche->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    boutonGauche->show();

    QObject::connect(boutonGauche, SIGNAL(clicked()), game, SLOT(GoLeft()));
    }

    ClickableLabel *teamInfo = new ClickableLabel(game);
    teamInfo->setFixedSize(InfoWidth,InfoHeight);
    teamInfo->setText("Zone info-team");
    teamInfo->installEventFilter(game);
    teamInfo->move(WindowWidth-InfoWidth,WindowHeight-InfoHeight);
    teamInfo->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    teamInfo->setAlignment(Qt::AlignCenter);
    teamInfo->show();

    QLabel *zoneInfoText = new QLabel(game);
    zoneInfoText->setFixedSize(InfoWidth,InfoHeight);
    zoneInfoText->setText(QString::fromStdString(map->getCurrentPosition().getText()));
    zoneInfoText->setAlignment(Qt::AlignCenter);
    zoneInfoText->move(0,WindowHeight-InfoHeight);
    zoneInfoText->setWordWrap(true);
    zoneInfoText->show();

    QLabel *zoneTitleText = new QLabel(game);
    zoneTitleText->setFixedSize(TitleWidth,TitleHeight);
    zoneTitleText->setText(QString::fromStdString(map->getCurrentPosition().getName()));
    zoneTitleText->setAlignment(Qt::AlignCenter);
    zoneTitleText->move(0,0);
    zoneTitleText->setStyleSheet("QLabel{color:white;}");
    zoneTitleText->setWordWrap(true);
    zoneTitleText->show();

    QLabel *parametre = new QLabel(game);
    parametre->setFixedSize(TitleWidth,TitleHeight);
    parametre->setAlignment(Qt::AlignCenter);
    parametre->move(WindowWidth-TitleWidth,0);
    parametre->show();

    int tailleBouton(50);

    settings = new QPushButton("P", game);
    settings->setFixedSize(tailleBouton,tailleBouton);
    settings->move(WindowWidth-TitleWidth/2,20);
    settings->show();
    settings->setStyleSheet(styleBoutonRond);

    QObject::connect(settings, SIGNAL(clicked()), game, SLOT(afficheParametre()));

}

