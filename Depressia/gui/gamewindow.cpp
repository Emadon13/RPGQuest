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

using namespace std;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow (parent)
{
    setCursor(Qt::CrossCursor);

    int WindowWidth(1920);
    int WindowHeight(1080);

    setWindowTitle("Depressia");
    setWindowIcon(QIcon("../ressources/images/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    showFullScreen();

    CreateGameFrame();
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
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/backgroundMap.png")));
    setPalette(p);

    GameFrame gf(this);
}

void GameWindow::CreateBattleFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/backgroundMap.png")));
    setPalette(p);

    BattleFrame gf(this);
}

void GameWindow::CreateDialogFrame()
{
    ClearWidget();

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/background.png")));
    setPalette(p);

    DialogFrame *gf = new DialogFrame(this);
}

void GameWindow::CreateVideoFrame()
{
    ClearWidget();

    VideoFrame *vf = new VideoFrame(this);
}

GameWindow::~GameWindow(){

}

