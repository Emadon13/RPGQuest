#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QWidget>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

signals :
    void clicked();

public:
    Sprite(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

private slots:
    void nextFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QTimer *timer;
    QPixmap *spriteImage;
    int currentFrame;

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // SPRITE_H
