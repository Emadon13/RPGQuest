#ifndef SPRITETEMPLATE_H
#define SPRITETEMPLATE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class SpriteTemplate : public QObject, public QGraphicsItem
{
    Q_OBJECT

signals:
    void clicked(SpriteTemplate*);
    void done();

public:
    SpriteTemplate();

    SpriteTemplate(int nb, int w, int h, std::string s);

protected slots:
    virtual void nextFrame();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

    int width, height;

    int nbFrame;

    QString sprite;

    QTimer *timer;

    QPixmap *spriteImage;

    int currentFrame;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};
#endif // SPRITETEMPLATE_H
