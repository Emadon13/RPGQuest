#include "gamewindow.h"
#include "gui/frame/gameframe.h"
#include "gui/frame/dialogframe.h"
#include "gui/frame/videoframe.h"
#include "gui/frame/battleframe.h"
#include "gui/frame/itemframe.h"
#include "mainwindow.h"
#include "gui/clickable/clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <vector>
#include "logic/world/map.h"
#include "gui/window/itemwindow.h"
#include "logic/events/itemfound.h"
#include "logic/events/fight.h"
#include "logic/events/video.h"

using namespace std;

GameWindow::GameWindow(Game *g,QWidget *parent) :
    QMainWindow (parent)
{
    game=g;
    map=game->getMap();

    setCursor(Qt::CrossCursor);

    int WindowWidth(game->getWindowWidth());
    int WindowHeight(game->getWindowHeight());

    setWindowTitle("Depressia");
    setWindowIcon(QIcon("../ressources/images/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    showFullScreen();

    mapElement=map->getCurrentPosition();

    ShowFrame();
}

void GameWindow::ShowFrame()
{
    Event *event = mapElement.getEvent();

    if(!map->isEventHapp())
    {
        if(dynamic_cast<Dialog*>(event) != NULL)
        {
            CreateDialogFrame();
            map->setEventHapp();
        }
        else if(dynamic_cast<ItemFound*>(event) != NULL)
        {
            CreateItemFrame();
        }
        else if(dynamic_cast<Fight*>(event) != NULL)
        {
            CreateGameFrame();
        }
        /*else if(dynamic_cast<FinalScreen*>(event) != NULL)
        {
            CreateGameFrame();
        }*/
        else if(dynamic_cast<Video*>(event) != NULL)
        {
            CreateVideoFrame();
            map->setEventHapp();
        }
        else
        {
            CreateGameFrame();
        }
    }
    else
    {
        CreateGameFrame();
    }
}


void GameWindow::afficheItem()
{
    ItemWindow *itemWindow=new ItemWindow(this);
    itemWindow->show();
    map->setEventHapp();
    CreateGameFrame();
    setDisabled(true);
}

void GameWindow::resetFocus()
{
    setEnabled(true);
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

    GameFrame gf(this);
}

void GameWindow::CreateItemFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage()))));
    setPalette(p);

    ItemFrame itemFrame(this, map);
}

void GameWindow::CreateBattleFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage()))));
    setPalette(p);

    BattleFrame gf(this, map);
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

    VideoFrame *vf = new VideoFrame(this,map);
}

Map* GameWindow::GetMap()
{
    return this->map;
}

Game* GameWindow::GetGame()
{
    return this->game;
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

