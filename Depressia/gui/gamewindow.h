#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <vector>

using namespace std;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void ClearWidget();

public slots:
    void CreateBattleFrame();
    void CreateGameFrame();
    void CreateDialogFrame();
    void CreateVideoFrame();

private:

    QPalette *p;
};

#endif // GAMEWINDOW_H
