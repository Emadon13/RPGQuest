#include "globalspec.h"
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>

GlobalSpec::GlobalSpec(QObject *parent) : QObject(parent)
{
    this->mainW = new QWidget();
    this->mainW->resize(1280,720);
    this->mainW->show();
}
