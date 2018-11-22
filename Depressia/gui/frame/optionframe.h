#ifndef OPTIONFRAME_H
#define OPTIONFRAME_H
#include <QObject>
#include "gui/window/mainwindow.h"


class OptionFrame : QObject
{

    Q_OBJECT

public:
    OptionFrame(MainWindow *m);

    MainWindow *main;
};


#endif // OPTIONFRAME_H
