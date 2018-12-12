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
    void killEntity(Sprite *sprite);
    void damageEntity(Sprite *sprite);
    void deleteEntity(Sprite *sprite);
    void attackEntity(Sprite *sprite);
    void Attack();
    void Damage();
    void Kill();
    void nextTurn();
    void updateCurrentPlayer();
    void updateTurnInfo();
    void showSelection();
    void playMobTurn();
    void updateUI();

    //void choixSkill(int i);
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
    Sprite* teamSprite[Fight::nb_e];
    Sprite* ennemySprite[Fight::nb_e];

    Hero *allie;
    Mob *mob;
    Entity *current;
    Skill *skill;
    int skillNumber;

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

    QPushButton *selectionSkill[8];
    QPushButton *selectionObjet[8];
    QSignalMapper *signalMapper;

    QGraphicsScene *scene;
    QGraphicsView *view;

    ClickableLabel *c;

    int espacementBoutonH;
    int espacementBoutonV;
};

#endif // BATTLEFRAME_H
