#include "gameframe.h"
#include "gamewindow.h"
#include "mainwindow.h"
#include "logic/world/mapelement.h"
#include "clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>

GameFrame::GameFrame(GameWindow *g,MapElement mE)
{
    MapElement mapElement=mE;
    game=g;

    int WindowWidth(1920);
    int WindowHeight(1080);

    int BoutonWidth(96);
    int BoutonHeight(96);
    int BoutonMarge(100);

    int InfoWidth(750);
    int InfoHeight(200);

    int TitleWidth(500);
    int TitleHeight(100);

    if()

    ClickableLabel *boutonHaut = new ClickableLabel(game);
    boutonHaut->setPixmap(QPixmap("../ressources/images/fleche-haut.png"));
    boutonHaut->setFixedSize(BoutonWidth,BoutonHeight);
    boutonHaut->installEventFilter(game);
    boutonHaut->move((WindowWidth-BoutonWidth)/2,BoutonMarge);
    boutonHaut->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonHaut->show();

    ClickableLabel *boutonBas = new ClickableLabel(game);
    boutonBas->setPixmap(QPixmap("../ressources/images/fleche-bas.png"));
    boutonBas->setFixedSize(BoutonWidth,BoutonHeight);
    boutonBas->installEventFilter(game);
    boutonBas->move((WindowWidth-BoutonWidth)/2,(WindowHeight-BoutonHeight-BoutonMarge));
    boutonBas->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonBas->show();

    ClickableLabel *boutonDroite = new ClickableLabel(game);
    boutonDroite->setPixmap(QPixmap("../ressources/images/fleche-droite.png"));
    boutonDroite->setFixedSize(BoutonWidth,BoutonHeight);
    boutonDroite->installEventFilter(game);
    boutonDroite->move((WindowWidth-BoutonWidth-BoutonMarge),(WindowHeight-BoutonHeight)/2);
    boutonDroite->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonDroite->show();

    ClickableLabel *boutonGauche = new ClickableLabel(game);
    boutonGauche->setPixmap(QPixmap("../ressources/images/fleche-gauche.png"));
    boutonGauche->setFixedSize(BoutonWidth,BoutonHeight);
    boutonGauche->installEventFilter(game);
    boutonGauche->move(BoutonMarge,(WindowHeight-BoutonHeight)/2);
    boutonGauche->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonGauche->show();

    ClickableLabel *teamInfo = new ClickableLabel(game);
    teamInfo->setPixmap(QPixmap("../ressources/images/info-box.png"));
    teamInfo->setFixedSize(InfoWidth,InfoHeight);
    teamInfo->installEventFilter(game);
    teamInfo->move(WindowWidth-InfoWidth,0);
    teamInfo->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    teamInfo->show();

    QLabel *zoneInfoImage = new QLabel(game);
    zoneInfoImage->setPixmap(QPixmap("../ressources/images/info-box.png"));
    zoneInfoImage->setFixedSize(InfoWidth,InfoHeight);
    zoneInfoImage->move(0,0);
    zoneInfoImage->show();
    QLabel *zoneInfoText = new QLabel(game);
    zoneInfoText->setFixedSize(InfoWidth,InfoHeight);
    zoneInfoText->setText("Non c'est pas une foret !");
    zoneInfoText->setAlignment(Qt::AlignCenter);
    zoneInfoText->move(0,0);
    zoneInfoText->show();

    QLabel *zoneTitleImage = new QLabel(game);
    zoneTitleImage->setPixmap(QPixmap("../ressources/images/dialog-box.png"));
    zoneTitleImage->setFixedSize(TitleWidth,TitleHeight);
    zoneTitleImage->move(0,WindowHeight-TitleHeight);
    zoneTitleImage->show();
    QLabel *zoneTitleText = new QLabel(game);
    zoneTitleText->setFixedSize(TitleWidth,TitleHeight);
    zoneTitleText->setText("La foret");
    zoneTitleText->setAlignment(Qt::AlignCenter);
    zoneTitleText->move(0,WindowHeight-TitleHeight);
    zoneTitleText->show();

    QObject::connect(boutonHaut, SIGNAL(clicked()), game, SLOT(CreateGameFrame()));
    QObject::connect(boutonBas, SIGNAL(clicked()), game, SLOT(CreateDialogFrame()));
    QObject::connect(boutonDroite, SIGNAL(clicked()), game, SLOT(CreateVideoFrame()));

}

