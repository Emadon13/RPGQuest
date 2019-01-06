#include "mainwindow.h"
#include "gamewindow.h"
#include "gui/clickable/clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QMediaPlayer>
#include "logic/game.h"
#include "logic/world/map.h"
#include "gui/frame/optionframe.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   MainWindow                     ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class MainWindow

    Cette classe
*/

MainWindow::MainWindow(Game *g, QWidget *parent) :
    QMainWindow(parent)
{
    this->game=g;

    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("../ressources/musics/theme-principal.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    setCursor(Qt::CrossCursor);

    int WindowWidth(1280);
    int WindowHeight(720);

    setWindowTitle("Depressia");
    setWindowIcon(QIcon("../ressources/images/hud/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/backgrounds/background.png")));
    setPalette(p);


    setMainMenu();
}

void MainWindow::changeResolution(int w, int h, double r)
{
    game->setRatio(r);
    game->setWindowHeight(h);
    game->setWindowWidth(w);
}

void MainWindow::ClearWidget()
{
    QList<QWidget*> list = findChildren<QWidget*>();
    for (int i = 0; i < list.size(); ++i)
    {
        if((dynamic_cast<QMediaPlayer*>(list[i])==nullptr) && (dynamic_cast<QMediaPlaylist*>(list[i])==nullptr)){
            list[i]->deleteLater();
        }
    }
}

void MainWindow::CreateOptionFrame()
{
    ClearWidget();
    OptionFrame of(this);
}

void MainWindow::setMainMenu()
{
    ClearWidget();

    int WindowWidth(1280);
    int WindowHeight(720);

    int BoutonWidth(480);
    int BoutonHeight(100);

    int TitreWidth(780);
    int TitreHeight(200);

    int ImageWidth(250);
    int ImageHeight(250);

    int espacementV((WindowHeight-BoutonHeight*3-TitreHeight)/5);
    int espacementH((WindowWidth-BoutonWidth-ImageWidth*2)/4);

    int xBouton((WindowWidth-BoutonWidth)/2);
    int xTitre((WindowWidth-TitreWidth)/2);

    boutonPlay = new QPushButton("Jouer !", this);
    boutonOption = new QPushButton("Options !", this);
    boutonQuit = new QPushButton("Quitter !", this);

    boutonPlay->setFixedSize(BoutonWidth,BoutonHeight);
    boutonOption->setFixedSize(BoutonWidth,BoutonHeight);
    boutonQuit->setFixedSize(BoutonWidth,BoutonHeight);

    boutonPlay->setCursor(Qt::PointingHandCursor);
    boutonOption->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    boutonQuit->setCursor(Qt::PointingHandCursor);

    boutonPlay->show();
    boutonOption->show();
    boutonQuit->show();

    QLabel *titre = new QLabel(this);
    titre->setPixmap(QPixmap("../ressources/images/hud/titre.png"));
    titre->setFixedSize(TitreWidth,TitreHeight);
    titre->show();

    QLabel *imageRight = new QLabel(this);
    imageRight->setPixmap(QPixmap("../ressources/images/hud/icone.png"));
    imageRight->setFixedSize(ImageWidth,ImageHeight);
    imageRight->show();

    ClickableLabel *imageLeft = new ClickableLabel(this);
    imageLeft->setPixmap(QPixmap("../ressources/images/hud/icone.png"));
    imageLeft->setFixedSize(ImageWidth,ImageHeight);
    imageLeft->installEventFilter(this);
    imageLeft->show();

    titre->move(xTitre,espacementV);
    boutonPlay->move(xBouton,(espacementV*3+TitreHeight));
    boutonOption->move(xBouton,(espacementV*3+TitreHeight+BoutonHeight));
    boutonQuit->move(xBouton,(espacementV*3+TitreHeight+BoutonHeight*2));

    imageLeft->move(espacementH,WindowHeight-espacementV-ImageHeight);
    imageRight->move(espacementH*3+ImageWidth+BoutonWidth,WindowHeight-espacementV-ImageHeight);

    QObject::connect(boutonPlay, SIGNAL(clicked()), this, SLOT(launchGame()));
    QObject::connect(boutonPlay, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(boutonQuit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(boutonOption, SIGNAL(clicked()), this, SLOT(CreateOptionFrame()));
    QObject::connect(boutonPlay, SIGNAL(clicked()), music, SLOT(stop()));
    QObject::connect(boutonQuit, SIGNAL(clicked()), music, SLOT(stop()));

}

void MainWindow::loadResolution720(){

    changeResolution(1280,720,1.5);

}

void MainWindow::loadResolution768(){

    changeResolution(1366,768,1.406);

}

void MainWindow::loadResolution1080(){

    changeResolution(1920,1080,1);

}

void MainWindow::launchGame()
{
    GameWindow *gameWindow=new GameWindow(game);
    gameWindow->show();
}

MainWindow::~MainWindow()
{
}
