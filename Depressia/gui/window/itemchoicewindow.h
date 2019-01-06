#ifndef ITEMCHOICEWINDOW_H
#define ITEMCHOICEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include "gui/window/gamewindow.h"


class ItemChoiceWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void useItem();

public:
    ItemChoiceWindow(GameWindow *g, QWidget *parent = nullptr);

private:
    Game *game;

    QPalette *p;

    QPushButton *ok;
    QPushButton *retour;
    QSignalMapper *signalMapperObjet;
    QSignalMapper *signalMapperEntity;
    QPushButton *selectionObjet[8];
    QPushButton *selectionEntity[4];
    Inventory *inventory;
};

#endif // ITEMCHOICEWINDOW_H
