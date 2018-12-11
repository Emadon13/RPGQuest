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
    player = fight.nextPlayer();
    cout << player->getName() << endl;
    player = fight.nextPlayer();
    cout << player->getName() << endl;
    player = fight.nextPlayer();
    cout << player->getName() << endl;
    player = fight.nextPlayer();
    cout << player->getName() << endl;
    player = fight.nextPlayer();
    cout << player->getName() << endl;
    player = fight.nextPlayer();
    cout << player->getName() << endl;
    player = fight.nextPlayer();
    cout << player->getName() << endl;

    cout << fight.getMobs()[1]->getName() << endl;

    while(!fight.isEnded())
    {
        for (int i=0 ; i<Fight::nb_e ; i++)
            entities[i] = fight.getHeroes()[i];
        Entity* t  = fight.getMobs()[1]->choseEntity(entities);
    }



    s =  fight.getMobs()[1]->getMove(fight.getMobs()[1]->choseMove());
    s->call(*fight.getMobs()[1], target);
    cout << s->getSummary() << endl;
    cout << fight.getMobs()[1]->getMp() << endl;

    cout << game.getTeam()->getHero(0)->getHp() << endl;


    cout << fight.getHeroes()[0]->getName() << endl;
    */


    MainWindow w(&game);
    w.show();

    return app.exec();
}

