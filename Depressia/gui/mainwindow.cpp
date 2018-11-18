#include "mainwindow.h"
#include "gamewindow.h"
#include "clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QMediaPlayer>
#include "logic/game.h"

MainWindow::MainWindow(Game *game, QWidget *parent) :
    QMainWindow(parent)
{
    //ui->setupUi(this);
    this->game=game;

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("../ressources/musics/theme-principal.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    setCursor(Qt::CrossCursor);

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

    setWindowTitle("Depressia");
    setWindowIcon(QIcon("../ressources/images/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/background.png")));
    setPalette(p);

    boutonPlay = new QPushButton("Jouer !", this);
    boutonOption = new QPushButton("Options !", this);
    boutonQuit = new QPushButton("Quitter !", this);

    boutonPlay->setFixedSize(BoutonWidth,BoutonHeight);
    boutonOption->setFixedSize(BoutonWidth,BoutonHeight);
    boutonQuit->setFixedSize(BoutonWidth,BoutonHeight);

    boutonPlay->setCursor(Qt::PointingHandCursor);
    boutonOption->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    boutonQuit->setCursor(Qt::PointingHandCursor);

    QLabel *titre = new QLabel(this);
    titre->setPixmap(QPixmap("../ressources/images/titre.png"));
    titre->setFixedSize(TitreWidth,TitreHeight);

    QLabel *imageRight = new QLabel(this);
    imageRight->setPixmap(QPixmap("../ressources/images/icone.png"));
    imageRight->setFixedSize(ImageWidth,ImageHeight);

    ClickableLabel *imageLeft = new ClickableLabel(this);
    imageLeft->setPixmap(QPixmap("../ressources/images/icone.png"));
    imageLeft->setFixedSize(ImageWidth,ImageHeight);
    imageLeft->installEventFilter(this);

    titre->move(xTitre,espacementV);
    boutonPlay->move(xBouton,(espacementV*3+TitreHeight));
    boutonOption->move(xBouton,(espacementV*3+TitreHeight+BoutonHeight));
    boutonQuit->move(xBouton,(espacementV*3+TitreHeight+BoutonHeight*2));

    imageLeft->move(espacementH,WindowHeight-espacementV-ImageHeight);
    imageRight->move(espacementH*3+ImageWidth+BoutonWidth,WindowHeight-espacementV-ImageHeight);

    GameWindow gameWindow;

    QObject::connect(boutonPlay, SIGNAL(clicked()), this, SLOT(launchGame()));
    QObject::connect(boutonPlay, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(boutonQuit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(boutonPlay, SIGNAL(clicked()), music, SLOT(stop()));
    QObject::connect(boutonQuit, SIGNAL(clicked()), music, SLOT(stop()));
}

void MainWindow::launchGame()
{
    gameWindow=new GameWindow();
    gameWindow->show();
}

MainWindow::~MainWindow()
{
}
