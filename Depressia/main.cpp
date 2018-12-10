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
    Fight fight = FightLoader::generate(game.getTeam(), "../ressources/fights/first.txt");
    Skill* s;
    vector<Entity*> target;
    target.push_back(fight.getHeroes()[0]);




    cout << fight.getMobs()[1]->getName() << endl;
/*
    while(!fight.isEnded())
    {
    //    Hero h = fight.getMobs()[1]->choseEntity(fight.getHeroes());
    }
*/
    s =  fight.getMobs()[1]->getMove(fight.getMobs()[1]->choseMove());
    s->call(*fight.getMobs()[1], target);
    cout << s->getSummary() << endl;
    cout << fight.getMobs()[1]->getMp() << endl;

    cout << game.getTeam()->getHero(0)->getHp() << endl;


    MainWindow w(&game);
    w.show();

    return app.exec();
}

