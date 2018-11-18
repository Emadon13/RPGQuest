#include "battleframe.h"
#include "gamewindow.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <vector>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

BattleFrame::BattleFrame(GameWindow *g) : QObject()
{

    game=g;

}

