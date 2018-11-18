#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <iostream>
#include <fstream>

#include "gui/globalspec.h"
#include "gui/mainwindow.h"
#include "gui/gamewindow.h"
#include "logic/events/fight.h"
#include "logic/world/map.h"
#include"io/dialogloader.h"
#include"logic/game.h"

using namespace std;

GlobalSpec * globalSpec;

int main(int argc, char *argv[])
{


    // ------------ TEST VINCENT -----------------

    /*

    Game g;
    Map m = g.getMap();
    m.goUp();
    m.goRight();
    m.goUp();

    cout << m.getCurrentPosition().getName() << endl;

    if(m.getCurrentPosition().getEvent().getEventType() == dialog)
        for(int i=0 ; i<m.getCurrentPosition().getEvent().getDialog().getSize() ; i++)
            cout << m.getCurrentPosition().getEvent().getDialog().getElement(i).getText() << endl;

    */


    // ------------TEST QUENTIN ------------------
    QApplication app(argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    Game *game = new Game();

    MainWindow w(game);
    w.show();

    return app.exec();
}

