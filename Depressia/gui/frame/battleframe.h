#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H
#include "gui/window/gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QSignalMapper>
#include "gui/frame/characterui.h"
#include "gui/frame/enemyui.h"
#include "logic/events/fight.h"

class BattleFrame : QObject
{
    Q_OBJECT

public slots :
    void killEntity(Entity *sprite);
    void damageEntity(Entity *sprite, unsigned long long i);
    void effectEntity(Entity *sprite, unsigned long long i);
    void deleteEntity(Entity *sprite);
    void attackEntity(Entity *sprite);
    void skillEntity(Entity *sprite);
    void nextTurn();
    void updateCurrentPlayer();
    void updateTurnInfo();
    void showSelection();
    void playTurn();
    void playTurnObject(QString summary);
    void updateUI();
    void callSkill();
    void playDamage();
    void playSkillEffect();
    void resetCurrentSprite();
    void resetHitedSprite(unsigned long long);
    void hideSprite(unsigned long long);
    void stopEffect(unsigned long long i);

    void useObjet();
    void callAttack();
    void choixEntity(int i);
    void choixEntityObjet(int i);
    void choixSkill(int i);
    void choixObjet(int i);

    void showObjet();
    void showSkill();

public:
    BattleFrame(GameWindow *game);

    GameWindow *game;

    Fight* fight;
    Inventory* inventory;

    QMediaPlaylist *playlist;
    QMediaPlayer *music;

    CharacterUI* teamUI[Fight::nb_e];
    EnemyUI* ennemyUI[Fight::nb_e];
    SpriteTemplate* teamSprite[Fight::nb_e][5];
    SpriteTemplate* ennemySprite[Fight::nb_e][5];
    SpriteTemplate* spriteEffect[Fight::nb_e*2];

    Hero *allie;
    Mob *mob;
    Entity *current;
    int skillNumber;
    int objectNumber;
    vector<Entity*> hited;

    CharacterUI *character;
    EnemyUI *enemy;

    QLabel *dialogInfo;
    QLabel *dialogSelection;
    QLabel *dialogCurrent;

    QPushButton *attack;
    QPushButton *sorts;
    QPushButton *objet;
    QPushButton *fuite;
    QPushButton *retour;
    QPushButton *next;
    QPushButton *previous;
    QPushButton *ok;
    QPushButton *okSkill;
    QPushButton *okObjet;

    QPushButton *selectionEntity[8];
    QPushButton *selectionEntityObject[8];
    QPushButton *selectionSkill[8];
    QPushButton *selectionObjet[8];
    QSignalMapper *signalMapperSkill;
    QSignalMapper *signalMapperObjet;
    QSignalMapper *signalMapperEntity;
    QSignalMapper *signalMapperEntityObjet;

    QGraphicsScene *scene;
    QGraphicsView *view;

    ClickableLabel *c;

    int espacementBoutonH;
    int espacementBoutonV;
};

#endif // BATTLEFRAME_H
