#include "sprite.h"
#include "iostream"

Sprite::Sprite(int nbFrameN, int widthN, int heightN, std::string spriteNormal,
               int nbFrameD, int widthD, int heightD, std::string spriteDamage,
               int nbFrameA, int widthA, int heightA, std::string spriteAttack,
               int nbFrameS, int widthS, int heightS, std::string spriteSkill,
               int nbFrameK, int widthK, int heightK, std::string spriteKilled)
               : QObject(), QGraphicsItem()
{
    this->damageSprite=QString::fromStdString(spriteDamage);
    this->normalSprite=QString::fromStdString(spriteNormal);
    this->attackSprite=QString::fromStdString(spriteAttack);
    this->killedSprite=QString::fromStdString(spriteKilled);
    this->skillSprite=QString::fromStdString(spriteSkill);

    this->currentFrame = 0;
    this->width=widthN;
    this->height=heightN;

    this->nbFrameAttack=nbFrameA;
    this->nbFrameDamage=nbFrameD;
    this->nbFrameKilled=nbFrameK;
    this->nbFrameNormal=nbFrameN;
    this->nbFrameSkill=nbFrameS;

    this->widthAttack=widthA;
    this->widthDamage=widthD;
    this->widthKilled=widthK;
    this->widthNormal=widthN;
    this->widthSkill=widthS;

    this->heightAttack=heightA;
    this->heightDamage=heightD;
    this->heightKilled=heightK;
    this->heightNormal=heightN;
    this->heightSkill=heightS;

    spriteImage = new QPixmap(normalSprite);

    timerN = new QTimer();
    timerK = new QTimer();
    timerD = new QTimer();
    timerA = new QTimer();
    timerS = new QTimer();

    connect(timerN, &QTimer::timeout, this, &Sprite::nextNormalFrame);
    connect(timerK, &QTimer::timeout, this, &Sprite::nextKillFrame);
    connect(timerD, &QTimer::timeout, this, &Sprite::nextDamageFrame);
    connect(timerA, &QTimer::timeout, this, &Sprite::nextAttackFrame);
    connect(timerS, &QTimer::timeout, this, &Sprite::nextSkillFrame);

    timerN->start(100);
}

QRectF Sprite::boundingRect() const
{
    return QRectF(0,0,width,height);
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
    painter->drawPixmap(0,0, *spriteImage, currentFrame, 0, width,height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Sprite::normal()
{
    spriteImage = new QPixmap(normalSprite);
    currentFrame = 0;
    timerN->start(100);
}

void Sprite::kill()
{
    timerN->stop();
    spriteImage = new QPixmap(damageSprite);
    currentFrame = 0;
    timerK->start(100);
}

void Sprite::attack()
{
    timerN->stop();
    spriteImage = new QPixmap(attackSprite);
    currentFrame = 0;
    timerA->start(100);
}

void Sprite::damage()
{
    timerN->stop();
    spriteImage = new QPixmap(damageSprite);
    currentFrame = 0;
    timerD->start(100);
}

void Sprite::skill()
{
    timerN->stop();
    spriteImage = new QPixmap(skillSprite);
    currentFrame = 0;
    timerS->start(100);
}

void Sprite::nextNormalFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += widthNormal;
    if (currentFrame >= widthNormal*nbFrameNormal ) currentFrame = 0;
    this->update(0,0,widthNormal,heightNormal);
}

void Sprite::nextDamageFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += widthDamage;
    if (currentFrame >= widthDamage*nbFrameDamage ) {
        timerD->stop();
        normal();
        currentFrame = 0;
    }
    else this->update(0,0,widthDamage,heightDamage);
}

void Sprite::nextAttackFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += widthAttack;
    if (currentFrame >= widthAttack*nbFrameAttack ) {
        normal();
        emit attackDone();
        timerA->stop();
        currentFrame = 0;
    }
    else this->update(0,0,widthAttack,heightAttack);
}

void Sprite::nextSkillFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += widthKilled;
    if (currentFrame >= widthKilled*nbFrameKilled ) {
        normal();
        emit attackDone();
        timerS->stop();
        currentFrame = 0;
    }
    else this->update(0,0,widthKilled,heightKilled);
}

void Sprite::nextKillFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += widthKilled;
    if (currentFrame >= widthKilled*nbFrameKilled ) {
        emit killed(this);
        currentFrame = 0;
    }
    else this->update(0,0,widthKilled,heightKilled);
}

void Sprite::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(this);
}
