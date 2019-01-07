#include "gamewindow.h"
#include "gui/frame/gameframe.h"
#include "gui/frame/dialogframe.h"
#include "gui/frame/videoframe.h"
#include "gui/frame/battleframe.h"
#include "gui/frame/itemframe.h"
#include "gui/frame/gameoverframe.h"
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
#include "gui/window/characterwindow.h"
#include "gui/window/settingswindow.h"
#include "logic/events/itemfound.h"
#include "logic/events/fight.h"
#include "logic/events/video.h"
#include "logic/events/finalscreen.h"
#include "gui/frame/finalframe.h"
#include "logic/events/save.h"
#include "gui/window/itemchoicewindow.h"
#include "gui/frame/saveframe.h"
#include "gui/frame/addheroframe.h"
#include "gui/window/savewindow.h"

using namespace std;

////////////////////////////////////////////////////////
///                                                  ///
///                   GameWindow                     ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class GameWindow

    Cette classe
*/

GameWindow::GameWindow(Game *g,QWidget *parent) :
    QMainWindow (parent)
{
    game=g;
    map=game->getMap();

    setCursor(Qt::CrossCursor);

    WindowWidth=game->getWindowWidth();
    WindowHeight=game->getWindowHeight();

    setWindowTitle("Depressia");
    setWindowIcon(QIcon("../ressources/images/hud/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    showFullScreen();

    mapElement=map->getCurrentPosition();

    ShowFrame();

    game->save();
}

void GameWindow::ShowFrame()
{
    event = mapElement.getEvent();

    if(!map->isEventHapp())
    {
        if(dynamic_cast<Dialog*>(event) != nullptr)
        {
            CreateDialogFrame();
            map->setEventHapp();
        }
        else if(dynamic_cast<ItemFound*>(event) != nullptr)
        {
            CreateItemFrame();
        }
        else if(dynamic_cast<Save*>(event) != nullptr)
        {
            CreateSaveFrame();
        }
        /*else if(dynamic_cast<newAlly*>(event) != nullptr)
        {
            CreateAddHeroFrame();
            map->setEventHapp();
        }*/
        else if(dynamic_cast<FinalScreen*>(event) != nullptr)
        {
            CreateFinalFrame();
        }
        else if(dynamic_cast<Video*>(event) != nullptr)
        {
            CreateVideoFrame();
            map->setEventHapp();
        }
        else if(dynamic_cast<Fight*>(event) != nullptr)
        {
            CreateBattleFrame();
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

void GameWindow::openCharacterWindow(Hero *allie)
{
    CharacterWindow *characterWindow=new CharacterWindow(this,allie);
    characterWindow->show();
    setDisabled(true);
}

void GameWindow::afficheParametre()
{
    SettingsWindow *settingsWindow=new SettingsWindow(this);
    settingsWindow->show();
    setDisabled(true);
}

void GameWindow::afficheSave()
{
    SaveWindow *saveWindow=new SaveWindow(this);
    saveWindow->show();
    setDisabled(true);
}

void GameWindow::makeSave()
{
    dynamic_cast<Save*>(event)->save(this->GetGame());
}

void GameWindow::healTeam()
{
    dynamic_cast<Save*>(event)->heal(this->GetGame()->getTeam());
}

void GameWindow::afficheItemList()
{
    ItemChoiceWindow *inventoyWindow=new ItemChoiceWindow(this);
    inventoyWindow->show();
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
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage())).scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    GameFrame *gf = new GameFrame(this);
    Q_UNUSED(gf);
}

void GameWindow::CreateFinalFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage())).scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    FinalFrame ff(this);
}

void GameWindow::CreateGameOverFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/backgrounds/gameover_screen.jpg").scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    GameOverFrame gof(this);
}

void GameWindow::CreateItemFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage())).scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    ItemFrame itemFrame(this);
}

void GameWindow::CreateBattleFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(((dynamic_cast<Fight*>(map->getCurrentPosition().getEvent()))->getImage())->scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    BattleFrame *bf = new BattleFrame(this);
    Q_UNUSED(bf);
}

void GameWindow::CreateDialogFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage())).scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    DialogFrame *df = new DialogFrame(this);
    Q_UNUSED(df);
}

void GameWindow::CreateAddHeroFrame()
{/*
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage())).scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    AddHeroFrame *ahf = new AddHeroFrame(this);
    Q_UNUSED(ahf);*/
}

void GameWindow::CreateSaveFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap(QString::fromStdString(map->getCurrentPosition().getImage())).scaled(WindowWidth,WindowHeight)));
    setPalette(p);

    SaveFrame *sf = new SaveFrame(this);
    Q_UNUSED(sf);
}

void GameWindow::CreateVideoFrame()
{
    ClearWidget();

    VideoFrame *vf = new VideoFrame(this);
    Q_UNUSED(vf);
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

void GameWindow::setPositionAfterLoose()
{
    ShowFrame();
}

GameWindow::~GameWindow(){

}

