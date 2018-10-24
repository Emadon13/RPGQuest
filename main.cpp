#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "io/entityloader.h"

using namespace std;

int main(int argc, char *argv[])
{

// ----------------- TEST VINCENT -----------------------

    cout << "test" << endl;




// --------------- TEST QUENTIN ---------------------

    QApplication app(argc, argv);

    QPushButton bouton("Bonjour Quentin");
    bouton.show();

// --------------- FIN TEST -------------------------

    return app.exec();
}
