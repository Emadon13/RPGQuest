#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include "gamewindow.h"
#include "logic/game.h"
#include "logic/world/map.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Game *game, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void launchGame();
    void changeResolution();

private:
    Game *game;

    QMediaPlaylist *playlist;
    QMediaPlayer *music;

    GameWindow *gameWindow;

    QPushButton *boutonPlay;
    QPushButton *boutonOption;
    QPushButton *boutonQuit;

    QPalette *p;

    QLabel *imageRight;
    QLabel *imageLeft;
    QLabel *titre;
};

#endif // MAINWINDOW_H
