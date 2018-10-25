#include <QApplication>
#include <QPushButton>
<<<<<<< HEAD
#include <iostream>
#include "logic/entities/entity.h"

using namespace std;

int main(int argc, char *argv[])
{

// ----------------- TEST VINCENT -----------------------
    Entity test;

    cout << test.getName() << endl;




// --------------- TEST QUENTIN ---------------------

=======
#include "logic/entities/entity.h"

int main(int argc, char *argv[])
{
>>>>>>> parent of 5f3c68b... entity loader
    QApplication app(argc, argv);

    Entity e;

    QPushButton bouton("Bonjour Quentin");
    bouton.show();

    return app.exec();
}
