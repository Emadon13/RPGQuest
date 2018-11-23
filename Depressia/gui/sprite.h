#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

signals:
    void clicked(Sprite*);
    void killed(Sprite*);

public:
    Sprite();

public slots :
    void kill();

private slots:
    void nextFrame();
    void nextKillFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QTimer *timer;
    QTimer *timerD;
    QPixmap *spriteImage;
    int currentFrame;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SPRITE_H
