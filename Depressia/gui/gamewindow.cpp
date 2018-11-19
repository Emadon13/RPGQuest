#include "gamewindow.h"
#include "gameframe.h"
#include "dialogframe.h"
#include "videoframe.h"
#include "battleframe.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>
#include "logic/world/map.h"

using namespace std;

GameWindow::GameWindow(Map *m,QWidget *parent) :
    QMainWindow (parent)
{
    map=m;

    setCursor(Qt::CrossCursor);

    int WindowWidth(1920);
    int WindowHeight(1080);

    setWindowTitle("Depressia");
    setWindowIcon(QIcon("../ressources/images/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    showFullScreen();

    mapElement=map->getCurrentPosition();

    ShowFrame();
}

void GameWindow::ShowFrame()
{
    EventType eventType = mapElement.getEvent().getEventType();
    if(eventType == dialog)
    {
        CreateDialogFrame();
    }
    else if(eventType == item_found)
    {
        CreateGameFrame();
    }
    else if(eventType == fight)
    {
        CreateGameFrame();
    }
    else if(eventType == final_screen)
    {
        CreateGameFrame();
    }
    else
    {
        CreateGameFrame();
    }
}

void GameWindow::ClearWidget()
{
    QList<QWidget*> list = findChildren<QWidget*>();
    for (int i = 0; i < list.size(); ++i)
    {
        list[i]->deleteLater();
    }
}

void GameWindow::CreateGameFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage()))));
    setPalette(p);

    std::cout<<map->getCurrentPosition().getImage();

    GameFrame gf(this, map);
}

void GameWindow::CreateBattleFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage()))));
    setPalette(p);

    BattleFrame gf(this,map);
}

void GameWindow::CreateDialogFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage()))));
    setPalette(p);

    DialogFrame *df = new DialogFrame(this,map);
}

void GameWindow::CreateVideoFrame()
{
    ClearWidget();

    VideoFrame *vf = new VideoFrame(this);
}

Map* GameWindow::GetMap()
{
    return this->map;
}

void GameWindow::GoRight()
{
    mapElement = map->goRight();
    ShowFrame();
}


void GameWindow::GoUp()
{
    mapElement = map->goUp();
    ShowFrame();
}

void GameWindow::GoLeft()
{
    mapElement = map->goLeft();
    ShowFrame();
}

void GameWindow::GoDown()
{
    mapElement = map->goDown();
    ShowFrame();
}
GameWindow::~GameWindow(){

}

