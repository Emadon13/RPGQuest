#pragma once

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
    void attackDone();

public:
    Sprite();

    Sprite(int nbFrameNormal, int widthNormal, int heightNormal, std::string spriteNormal,
           int nbFrameDamage, int widthDamage, int heightDamage, std::string spriteDamage,
           int nbFrameAttack, int widthAttack, int heightAttack, std::string spriteAttack,
           int nbFrameSkill, int widthSkill, int heightSkill, std::string spriteSkill,
           int nbFrameKilled, int widthKilled, int heightKilled, std::string spriteKilled);

public slots :
    void kill();
    void damage();
    void attack();
    void normal();
    void skill();

private slots:
    void nextNormalFrame();
    void nextAttackFrame();
    void nextKillFrame();
    void nextSkillFrame();
    void nextDamageFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

    int width, height;

    int nbFrameNormal, widthNormal, heightNormal;
    int nbFrameDamage, widthDamage, heightDamage;
    int nbFrameAttack, widthAttack, heightAttack;
    int nbFrameSkill, widthSkill, heightSkill;
    int nbFrameKilled, widthKilled, heightKilled;

    QString damageSprite;
    QString normalSprite;
    QString attackSprite;
    QString skillSprite;
    QString killedSprite;

    QTimer *timerN;
    QTimer *timerD;
    QTimer *timerK;
    QTimer *timerA;
    QTimer *timerS;

    QPixmap *spriteImage;

    int currentFrame;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SPRITE_H
