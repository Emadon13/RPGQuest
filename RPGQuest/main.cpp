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

    ofstream flux("../jeveuxtest.txt");
    if(flux) cout << "tout va bien" << endl;
    else cout << "MARCHE PAAAAS" << endl;


    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);

    QPushButton bouton("a");
    bouton.show();

    return app.exec();
//t bo
}
