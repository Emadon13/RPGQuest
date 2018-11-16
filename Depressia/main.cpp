#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>

#include "gui/globalspec.h"
#include "logic/events/fight.h"
#include "logic/world/map.h"
#include"logic/world/mapelement.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{


    // ------------ TEST VINCENT -----------------



    Map map;
    MapElement w;


    // ------------TEST QUENTIN ------------------
    QApplication app (argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    globalSpec = new GlobalSpec();
/*
    set up start Screen
    StartScreen * start = new StartScreen(*global);
    start->show();
*/
    return app.exec();

//t bo
}

