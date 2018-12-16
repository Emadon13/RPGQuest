#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H
#include "gui/window/gamewindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QSignalMapper>
#include "gui/sprite.h"
#include "gui/frame/characterui.h"
#include "gui/frame/enemyui.h"
#include "logic/events/fight.h"

class BattleFrame : QObject
{
    Q_OBJECT

public slots :
    void killEntity(Entity *sprite);
    void damageEntity(Entity *sprite);
    void deleteEntity(Entity *sprite);
    void attackEntity(Entity *sprite);
    void skillEntity(Entity *sprite);
    void nextTurn();
    void updateCurrentPlayer();
    void updateTurnInfo();
    void showSelection();
    void playTurn();
    void updateUI();
    void callSkill();
    void playDamage();
    void setCorrectSprite();

    void callAttack();
    void choixEntity(int i);
    void choixSkill(int i);
    //void choixObjet(int i);

    void showObjet();
    void showSkill();

public:
    BattleFrame(GameWindow *game);

    GameWindow *game;

    Fight* fight;

    QMediaPlaylist *playlist;
    QMediaPlayer *music;

    CharacterUI* teamUI[Fight::nb_e];
    EnemyUI* ennemyUI[Fight::nb_e];
    SpriteTemplate* teamSprite[Fight::nb_e][5];
    SpriteTemplate* ennemySprite[Fight::nb_e][5];

    Hero *allie;
    Mob *mob;
    Entity *current;
    int skillNumber;
    vector<Entity*> hited;

    CharacterUI *character;
    EnemyUI *enemy;

    Sprite *sprite;

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
    QPushButton *selectionSkill[8];
    QPushButton *selectionObjet[8];
    QSignalMapper *signalMapperSkill;
    QSignalMapper *signalMapperEntity;

    QGraphicsScene *scene;
    QGraphicsView *view;

    ClickableLabel *c;

    int espacementBoutonH;
    int espacementBoutonV;
};

#endif // BATTLEFRAME_H
