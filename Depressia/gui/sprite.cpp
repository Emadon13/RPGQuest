#include "sprite.h"

Sprite::Sprite(QString nS, QString dS) : QObject(), QGraphicsItem()
{
    this->damageSprite=dS;
    this->normalSprite=nS;

    currentFrame = 0;
    spriteImage = new QPixmap(normalSprite);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Sprite::nextFrame);
    timer->start(100);


}

QRectF Sprite::boundingRect() const
{
    return QRectF(0,0,112,192);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */
    painter->drawPixmap(0,0, *spriteImage, currentFrame, 0, 112,192);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Sprite::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += 112;
    if (currentFrame >= 672 ) currentFrame = 0;
    this->update(0,0,112,192);
}

void Sprite::kill()
{
    timer->stop();
    spriteImage = new QPixmap(damageSprite);
    currentFrame=0;
    timerD = new QTimer();
    connect(timerD, &QTimer::timeout, this, &Sprite::nextKillFrame);
    timerD->start(100);
}

void Sprite::nextKillFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += 112;
    if (currentFrame >= 672 ) {
        emit killed(this);
        currentFrame = 0;
    }
    else this->update(0,0,112,192);

}

void Sprite::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(this);
}