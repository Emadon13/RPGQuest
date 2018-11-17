#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void launchGame();

private:
    Ui::MainWindow *ui;

    QMediaPlaylist *playlist;
    QMediaPlayer *music;

    GameWindow *game;

    QPushButton *boutonPlay;
    QPushButton *boutonOption;
    QPushButton *boutonQuit;

    QPalette *p;

    QLabel *imageRight;
    QLabel *imageLeft;
    QLabel *titre;
};

#endif // MAINWINDOW_H
