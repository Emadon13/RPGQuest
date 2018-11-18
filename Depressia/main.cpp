#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>

#include "logic/game.h"
#include "gui/globalspec.h"
#include "gui/mainwindow.h"
#include "gui/gamewindow.h"
#include "logic/events/fight.h"
#include "logic/world/map.h"
#include"io/dialogloader.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{


    // ------------ TEST VINCENT -----------------

    Game g;
    cout << g.getMap().getCurrentPosition().getName() << endl;

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    MainWindow w;
    w.show();

    return app.exec();
}

void launchGame()
{
    GameWindow game;
    game.show();
}

