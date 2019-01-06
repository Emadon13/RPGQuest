#include "spritetemplate.h"
#include "iostream"

////////////////////////////////////////////////////////
///                                                  ///
///                   SpriteTemplate                 ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class SpriteTemplate

    Cette classe
*/

SpriteTemplate::SpriteTemplate(int nb, int w, int h, std::string s)
               : QObject(), QGraphicsItem()
{
    this->sprite=QString::fromStdString(s);

    this->currentFrame = 0;

    this->width=w;
    this->height=h;

    this->nbFrame=nb;

    this->width=w;

    this->height=h;

    spriteImage = new QPixmap(sprite);

    timer = new QTimer();
}

QRectF SpriteTemplate::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void SpriteTemplate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *spriteImage, currentFrame, 0, width,height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void SpriteTemplate::nextFrame()
{

}

int SpriteTemplate::getWidth()
{
   return width;
}

int SpriteTemplate::getHeight()
{
    return height;
}


void SpriteTemplate::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked(this);
}
