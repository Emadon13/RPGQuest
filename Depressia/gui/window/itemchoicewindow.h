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
    void showItemList();
    void showEntityList();
    void choixObjet(int i);
    void choixEntity(int i);

public:
    ItemChoiceWindow(GameWindow *g, QWidget *parent = nullptr);

private:
    Game *game;
    GameWindow *gameWindow;

    QLabel *image;
    QLabel *titre;
    QLabel *info;

    int ImageWidth;
    int ImageHeight;

    int itemNumber;

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
