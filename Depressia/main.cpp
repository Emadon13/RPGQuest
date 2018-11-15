#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>
#include "io/entityloader.h"
#include "gui/globalspec.h"
#include "logic/fight.h"
#include "logic/world/map.h"
#include"logic/world/window.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{


    // ------------ TEST VINCENT -----------------



    Map map;
    Window w;

    cout << map.w1.getTitle() << endl;
    cout << map.w2.getTitle() << endl;
    if(map.getCurrentWindow()->getDown() != nullptr) cout << map.getCurrentWindow()->getDown()->getTitle() << endl;
    if(map.getCurrentWindow()->getLeft() != nullptr) cout << map.getCurrentWindow()->getLeft()->getTitle() << endl;
    else cout << "exixte pas" << endl;
    cout << "qvqmzbvm" << endl;


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

