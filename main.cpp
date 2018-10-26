#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "io/entityloader.h"

using namespace std;

int main(int argc, char *argv[])
{

    // ------------ TEST VINCENT -----------------
    // cout << EntityLoader::generate() << endl;
    Entity e;
    cout << e.getName() << endl;

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);

    QPushButton bouton("Bonjour Quentin");
    bouton.show();

    return app.exec();
//t bo
}
