#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>
#include "io/entityloader.h"
#include "gui/globalspec.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{

    // ------------ TEST VINCENT -----------------

    EntityLoader el;
    Entity e = el.generate("../ressources/goblin.txt");
    cout << e.getName() << endl;

    // ------------TEST QUENTIN ------------------
    QApplication app (argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    globalSpec = new GlobalSpec();

    //set up start Screen
    StartScreen * start = new StartScreen(*global);
    start->show();

    return app.exec();
//t bo
}
