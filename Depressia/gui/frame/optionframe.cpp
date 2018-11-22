#include "optionframe.h"
#include "gui/window/mainwindow.h"

OptionFrame::OptionFrame(MainWindow *m) : QObject()
{

    main=m;

    int WindowWidth(1280);
    int WindowHeight(720);

    int BoutonWidth(480);
    int BoutonHeight(100);

    int espacement((WindowHeight-BoutonHeight*4)/5);

    QPushButton *Resolution1 = new QPushButton("1280  x 720", main);
    QPushButton *Resolution2 = new QPushButton("1366 x 768", main);
    QPushButton *Resolution3 = new QPushButton("1920 x 1080", main);
    QPushButton *Quitter = new QPushButton("Retour !", main);

    Resolution1->setFixedSize(BoutonWidth,BoutonHeight);
    Resolution2->setFixedSize(BoutonWidth,BoutonHeight);
    Resolution3->setFixedSize(BoutonWidth,BoutonHeight);
    Quitter->setFixedSize(BoutonWidth,BoutonHeight);

    Resolution1->setCursor(Qt::PointingHandCursor);
    Resolution2->setCursor(Qt::PointingHandCursor);
    Resolution3->setCursor(Qt::PointingHandCursor);
    Quitter->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));

    Resolution1->move((WindowWidth-BoutonWidth)/2,espacement);
    Resolution2->move((WindowWidth-BoutonWidth)/2,espacement*2+BoutonHeight);
    Resolution3->move((WindowWidth-BoutonWidth)/2,espacement*3+BoutonHeight*2);
    Quitter->move((WindowWidth-BoutonWidth)/2,espacement*4+BoutonHeight*3);

    Resolution1->show();
    Resolution2->show();
    Resolution3->show();
    Quitter->show();

    QObject::connect(Resolution1, SIGNAL(clicked()), main, SLOT(loadResolution720()));
    QObject::connect(Resolution2, SIGNAL(clicked()), main, SLOT(loadResolution768()));
    QObject::connect(Resolution3, SIGNAL(clicked()), main, SLOT(loadResolution1080()));
    QObject::connect(Quitter, SIGNAL(clicked()), main, SLOT(setMainMenu()));

}

