#include "settingswindow.h"

#include "logic/game.h"
#include "gui/window/gamewindow.h"
#include <QLabel>
#include "logic/events/itemfound.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   SettingsWindow                     ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class SettingsWindow

    Cette classe
*/

SettingsWindow::SettingsWindow(GameWindow *game, QWidget *parent) :
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

    int ImageWidth(250);
    int ImageHeight(250);

    int espacement=30;

    setWindowTitle("Settings");
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

    ok = new QPushButton("Retour", this);
    ok->setFixedSize(BoutonWidth,BoutonHeight);
    ok->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    ok->move((WindowWidth-BoutonWidth)/2,(WindowHeight-espacement-BoutonHeight));
    ok->setStyleSheet(styleBouton);
    ok->show();

    quit = new QPushButton("Quitter", this);
    quit->setFixedSize(BoutonWidth,BoutonHeight);
    quit->setCursor(QCursor(QPixmap("../ressources/images/hud/cursor.png"), 0, 0));
    quit->move((WindowWidth-BoutonWidth)/2+espacement*3,(WindowHeight/2-BoutonHeight/2));
    quit->setStyleSheet(styleBouton);
    quit->show();

    QLabel *image = new QLabel(this);
    image->setPixmap(QPixmap("../ressources/images/hud/settings-image.png"));
    image->setFixedSize(ImageWidth,ImageHeight);
    image->move(espacement*2,(WindowHeight-ImageHeight)/2);
    image->show();

    QLabel *titre = new QLabel(this);
    titre->setText("Parametres");
    titre->setFixedSize(TitreWidth,TitreHeight);
    titre->setAlignment(Qt::AlignCenter);
    titre->setWordWrap(true);
    titre->move(WindowWidth/2-espacement*3,0);
    titre->setStyleSheet("QLabel{color:white;}");
    titre->show();

    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(quit, SIGNAL(clicked()), game, SLOT(close()));
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ok, SIGNAL(clicked()), game, SLOT(resetFocus()));

}

