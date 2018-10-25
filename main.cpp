#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "logic/entities/entity.h"

using namespace std;

int main(int argc, char *argv[])
{

// ----------------- TEST VINCENT -----------------------
    Entity test;

    cout << test.getName() << endl;




// --------------- TEST QUENTIN ---------------------

    QApplication app(argc, argv);

    QPushButton bouton("Bonjour Quentin");
    bouton.show();

// --------------- FIN TEST -------------------------

    return app.exec();
}
