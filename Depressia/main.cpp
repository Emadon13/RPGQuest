#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>

#include "gui/globalspec.h"
#include "gui/window/mainwindow.h"
#include "gui/window/gamewindow.h"
#include "logic/events/fight.h"
#include "logic/world/map.h"
#include"io/dialogloader.h"
#include"logic/game.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    Game *game = new Game();

    MainWindow w(game);
    w.show();

    return app.exec();
}

