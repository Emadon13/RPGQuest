#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>
#include "io/entityloader.h"

using namespace std;

int main(int argc, char *argv[])
{

    // ------------ TEST VINCENT -----------------

    EntityLoader el;
    Entity e = el.generate("../ressources/goblin.txt");
    cout << e.getName() << endl;

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);

    QPushButton bouton("a");
    bouton.show();

    return app.exec();
//t bo
}
