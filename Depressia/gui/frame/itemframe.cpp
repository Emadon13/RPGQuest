#include "itemframe.h"
#include "gui/clickable/clickablelabel.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   ItemFrame                      ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class ItemFrame

    Cette classe
*/

ItemFrame::ItemFrame(GameWindow *g)
{
    game=g;
    map=game->GetMap();

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio(game->GetGame()->getRatio());

    int BoutonWidth(int(96/ratio));
    int BoutonHeight(int(96/ratio));
    int BoutonMarge(int(100/ratio));

    int ImageWidth(int(250/ratio));
    int ImageHeight(int(250/ratio));

    int InfoWidth(int(750/ratio));
    int InfoHeight(int(200/ratio));

    int TitleWidth(int(500/ratio));
    int TitleHeight(int(100/ratio));

    QLabel *back = new QLabel(game);
    back->setPixmap(QPixmap("../ressources/images/hud/background-game-3.png").scaled(WindowWidth,WindowHeight));
    back->setFixedSize(WindowWidth,WindowHeight);
    back->move(0,0);
    back->show();

    ClickableLabel *item = new ClickableLabel(game);
    item->setPixmap(QPixmap("../ressources/images/hud/icone.png").scaled(ImageWidth,ImageWidth));
    item->setFixedSize(ImageWidth,ImageHeight);
    item->installEventFilter(game);
    item->move((WindowWidth-ImageWidth)/2,(WindowHeight-ImageHeight)/2);
    item->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    item->show();

    QObject::connect(item, SIGNAL(clicked()), game, SLOT(afficheItem()));

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
    parametre->setText("Zone parametre");
    parametre->setAlignment(Qt::AlignCenter);
    parametre->move(WindowWidth-TitleWidth,0);
    parametre->show();
}

