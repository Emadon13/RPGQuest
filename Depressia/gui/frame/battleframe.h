#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H
#include "gui/window/gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gui/sprite.h"


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

    Sprite *sprite;
    Sprite *sprite2;

    QGraphicsScene *scene;
    QGraphicsView *view;

    ClickableLabel *c;
};

#endif // BATTLEFRAME_H
