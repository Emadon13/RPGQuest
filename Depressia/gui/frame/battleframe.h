#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H
#include "gui/window/gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gui/sprite.h"
#include "gui/frame/characterui.h"
#include "gui/frame/enemyui.h"


class BattleFrame : QObject
{
    Q_OBJECT

public slots :
    void killEntity(Sprite *sprite);
    void damageEntity(Sprite *sprite);
    void deleteEntity(Sprite *sprite);
    void attackEntity(Sprite *sprite);
    void Attack();
    void Damage();
    void Kill();

public:
    BattleFrame(GameWindow *game);

    GameWindow *game;

    Entity *bonasse;
    Entity *rozalin;

    CharacterUI *character;
    EnemyUI *enemy;

    Sprite *sprite;
    Sprite *sprite2;

    QLabel *dialogInfo;

    QGraphicsScene *scene;
    QGraphicsView *view;

    ClickableLabel *c;
};

#endif // BATTLEFRAME_H
