#include <QApplication>
#include <QPushButton>
#include "logic/entities/entity.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Entity e;

    QPushButton bouton(e.getName());
    bouton.show();

    return app.exec();
}
