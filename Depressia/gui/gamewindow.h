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

public slots:
    void CreateBattleFrame();
    void CreateGameFrame();
    void CreateDialogFrame();

private:
    QLabel *boutonHaut;
    QLabel *boutonBas;
    QLabel *boutonDroite;
    QLabel *boutonGauche;

    QPalette *p;

    void ClearWidget();
};

#endif // GAMEWINDOW_H
