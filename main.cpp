#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "logic/entities/entity.h"
#include "io/test.h"


using namespace std;

int main(int argc, char *argv[])
{

    // ------------ TEST VINCENT -----------------

    test t;
    Entity e;
    cout << t.generate() << endl;

    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);

    QPushButton bouton("a");
    bouton.show();

    return app.exec();
//t bo
}
