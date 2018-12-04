#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include "logic/entities/entity.h"

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

signals:
    void clicked(Sprite*);
    void killed(Sprite*);

public:
    Sprite(Entity *e,QString normalSprite, QString damageSprite, QString attackSprite);
    Entity* getEntity();

public slots :
    void kill();
    void damage();
    void attack();
    void normal();

private slots:
    void nextFrame();
    void nextAttackFrame();
    void nextKillFrame();
    void nextDamageFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString damageSprite;
    QString normalSprite;
    QString attackSprite;

private:
    Entity *perso;
    QTimer *timer;
    QTimer *timerD;
    QTimer *timerK;
    QTimer *timerA;
    QPixmap *spriteImage;
    int currentFrame;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SPRITE_H
