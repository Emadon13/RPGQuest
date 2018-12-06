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
#include "logic/skills/recover.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{
    // ------------TEST VINCENT ------------------
    /*
    Entity e1, e2;
    Recover r("atterissage", "", 0, one, 1.0);

    cout << e1.getHp() << endl;
    cout << e2.getHp() << endl;

    cout << e1.hitOpponent(e2) << endl;

    cout << e1.getHp() << endl;
    cout << e2.getHp() << endl;

    r.call(e1,e2);
    cout << r.getSummary() << endl;

    cout << e1.getHp() << endl;
    cout << e2.getHp() << endl;
    */

    cout << "izubqziuvbpqziuhvpZVBZIEY" << endl;

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    Game *game = new Game();

    MainWindow w(game);
    w.show();

    return app.exec();
}

