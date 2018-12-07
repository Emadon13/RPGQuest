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

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    Game game = Game();

    cout << game.team.getHero(0)->getSkillsSize() << endl;
    game.team.getHero(0)->addXp(111);
    game.team.getHero(0)->takeDamage(4);


    MainWindow w(&game);
    w.show();

    return app.exec();
}

