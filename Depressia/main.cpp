#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>

#include "gui/globalspec.h"
#include "gui/window/mainwindow.h"
#include "gui/window/gamewindow.h"
#include "io/fightloader.h"
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

    /*
    player = fight->nextPlayer();
    cout << player->getName() << endl;

    player = fight->nextPlayer();
    cout << player->getName() << endl;
    player = fight->nextPlayer();
    cout << player->getName() << endl;
    player = fight->nextPlayer();
    cout << player->getName() << endl;
    player = fight->nextPlayer();
    cout << player->getName() << endl;
    player = fight->nextPlayer();
    cout << player->getName() << endl;
    player = fight->nextPlayer();
    cout << player->getName() << endl;
*/
    //cout << fight->getMobs()[1]->getName() << endl;

    /*
    while(!fight->isEnded())
    {
        Entity* e = fight->nextPlayer();
        if(dynamic_cast<Mob*>(e) != nullptr)
        {
            int i = dynamic_cast<Mob*>(e)->chooseMove();

            fight->target(dynamic_cast<Mob*>(e), i);
            cout << e->getSkillSummary(i) << endl;
        }
    }
*/

    MainWindow w(&game);
    w.show();

    return app.exec();
}

