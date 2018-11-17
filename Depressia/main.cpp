#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>

#include "gui/globalspec.h"
#include "logic/events/fight.h"
#include "logic/world/map.h"
#include"io/dialogloader.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{


    // ------------ TEST VINCENT -----------------
    DialogLoader dl;
    vector<Dialog> d = dl.generate("../ressources/loaders/dialogs.txt");

    cout << d.at(0).getElement(0).getText() << endl;
    cout << d.at(0).getElement(1).getText() << endl;
    cout << d.at(0).getElement(2).getText() << endl;

    cout << d.at(1).getElement(0).getText() << endl;
    cout << d.at(1).getElement(1).getText() << endl;

    cout << d.at(1).getElement(2).getText() << endl;


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

