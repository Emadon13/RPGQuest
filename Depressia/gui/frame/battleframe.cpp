#include "gui/frame/battleframe.h"
#include "gui/window/gamewindow.h"
#include "gui/window/mainwindow.h"
#include "gui/clickable/clickablelabel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <vector>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "gui/sprite/sprite.h"
#include "gui/clickable/clickablelabel.h"
#include "gui/frame/characterui.h"
#include "gui/frame/enemyui.h"
#include "gui/sprite/spriteloop.h"
#include "gui/sprite/spriteunique.h"
#include "io/spriteloader.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   BattleFrame                    ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class BattleFrame

    Cette classe gère l'affichage de la bataille sur la GameWindow.
*/

////////////////////////////////////////////////////////
///                                                  ///
///                   Constructeur                   ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn BattleFrame::BattleFrame(GameWindow *g) : QObject()

    Construit une BattleFrame sur la GameWindow passée en parametre en fonction d'un objet fight :

        - Initialise tous les sprites de toutes les entités (sprite normal, de dommage, d'attaque, de sort, de mort)
        - Initialise les UI de toutes les entités (enneyUI et heroUI)
        - Initialise tous les boutons qui serviront pour l'interaction de l'utilisateur
        - Lance une musique
        - Initialise les différentes zones qui serviront pour l'affichage de certaines informations
        - Initialise le background, le curseur, la police, etc, ...

*/
BattleFrame::BattleFrame(GameWindow *g) : QObject()
{
    game=g;

    fight=((dynamic_cast<Fight*>(game->GetGame()->getMap()->getCurrentPosition().getEvent())));

    inventory=game->GetGame()->getTeam()->getInventory();

    ///Lancement de la musique
    playlist = new QMediaPlaylist();
    playlist->addMedia(*fight->getMusic());
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio(game->GetGame()->getRatio());

    ///Affichage de l'image qui sert de décors pour l'interface.
    QLabel *back = new QLabel(game);
    back->setPixmap(QPixmap("../ressources/images/hud/background-battle9.png").scaled(WindowWidth,WindowHeight));
    back->setFixedSize(WindowWidth,WindowHeight);
    back->move(0,0);
    back->show();

    ///Création de la scene qui contiendra les différents sprites
    scene = new QGraphicsScene(game);
    scene->setSceneRect(0, 0, WindowWidth, WindowHeight);

    view = new QGraphicsView(game);
    view->setScene(scene);
    view->show();
    view->move(0,0);
    view->setStyleSheet("background-color: transparent;");
    view->setFrameStyle(QFrame::NoFrame);
    view->setFixedSize(WindowWidth,WindowHeight);

    int espacementUI=50;
    int tailleUI = int((game->GetGame()->getWindowHeight()-espacementUI*5)/4);
    int espacementSprite=int(150/ratio);
    int espacementMilieu=int(50/ratio);

    ///Création des Sprites et des UI pour les heros
    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        allie=fight->getHeroes()[i];

        if(allie != nullptr)
        {
            teamSprite[i][0] = allie->getSpriteNormal();
            if(i%2==0) teamSprite[i][0]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2))));
            else teamSprite[i][0]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            teamSprite[i][0]->setToolTip(QString::fromStdString(allie->getName()));
            scene->addItem(teamSprite[i][0]);

            teamSprite[i][1] = allie->getSpriteAttack();
            if(i%2==0) teamSprite[i][1]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2))));
            else teamSprite[i][1]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            teamSprite[i][1]->setToolTip(QString::fromStdString(allie->getName()));
            scene->addItem(teamSprite[i][1]);
            teamSprite[i][1]->hide();

            teamSprite[i][2] = allie->getSpriteSkill();
            if(i%2==0) teamSprite[i][2]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2))));
            else teamSprite[i][2]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            teamSprite[i][2]->setToolTip(QString::fromStdString(allie->getName()));
            scene->addItem(teamSprite[i][2]);
            teamSprite[i][2]->hide();

            teamSprite[i][3] = allie->getSpriteDamage();
            if(i%2==0) teamSprite[i][3]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2))));
            else teamSprite[i][3]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            teamSprite[i][3]->setToolTip(QString::fromStdString(allie->getName()));
            scene->addItem(teamSprite[i][3]);
            teamSprite[i][3]->hide();

            teamSprite[i][4] = allie->getSpriteKilled();
            if(i%2==0) teamSprite[i][4]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2))));
            else teamSprite[i][4]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            teamSprite[i][4]->setToolTip(QString::fromStdString(allie->getName()));
            scene->addItem(teamSprite[i][4]);
            teamSprite[i][4]->hide();

            teamUI[i] = new CharacterUI(game,allie,game->GetGame()->getWindowWidth()-espacementUI-tailleUI,espacementUI*(i+1)+tailleUI*i,tailleUI,tailleUI);

        }
        else
        {
            teamUI[i]=nullptr;
        }
    }

    ///Création des Sprites et des UI pour les mobs
    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        mob=fight->getMobs()[i];

        if(mob != nullptr)
        {
            ennemySprite[i][0] = mob->getSpriteNormal();
            if(i%2==1) ennemySprite[i][0]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2))));
            else ennemySprite[i][0]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            ennemySprite[i][0]->setToolTip(QString::fromStdString(mob->getName()));
            scene->addItem(ennemySprite[i][0]);

            ennemySprite[i][1] = mob->getSpriteAttack();
            if(i%2==1) ennemySprite[i][1]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2))));
            else ennemySprite[i][1]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            ennemySprite[i][1]->setToolTip(QString::fromStdString(mob->getName()));
            scene->addItem(ennemySprite[i][1]);
            ennemySprite[i][1]->hide();

            ennemySprite[i][2] = mob->getSpriteSkill();
            if(i%2==1) ennemySprite[i][2]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2))));
            else ennemySprite[i][2]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            ennemySprite[i][2]->setToolTip(QString::fromStdString(mob->getName()));
            scene->addItem(ennemySprite[i][2]);
            ennemySprite[i][2]->hide();

            ennemySprite[i][3] = mob->getSpriteDamage();
            if(i%2==1) ennemySprite[i][3]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2))));
            else ennemySprite[i][3]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            ennemySprite[i][3]->setToolTip(QString::fromStdString(mob->getName()));
            scene->addItem(ennemySprite[i][3]);
            ennemySprite[i][3]->hide();

            ennemySprite[i][4] = mob->getSpriteKilled();
            if(i%2==1) ennemySprite[i][4]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2))));
            else ennemySprite[i][4]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            ennemySprite[i][4]->setToolTip(QString::fromStdString(mob->getName()));
            scene->addItem(ennemySprite[i][4]);
            ennemySprite[i][4]->hide();

            ennemyUI[i] = new EnemyUI(game,mob,espacementUI,espacementUI*(i+1)+tailleUI*i,tailleUI,tailleUI);
        }
        else
        {
            ennemyUI[i]=nullptr;
        }
    }

    ///Initialisation des différents Label qui contiendront les textes.
    int dialogWidth(int(WindowWidth*0.4));
    int dialogHeight(int(WindowHeight*0.19));

    dialogCurrent = new QLabel(game);
    dialogCurrent->setText("Combat !");
    dialogCurrent->setFixedSize(int(dialogWidth*0.2),int(dialogHeight*0.2));
    dialogCurrent->move(WindowWidth/2-dialogCurrent->width()/2,0);
    dialogCurrent->setAlignment(Qt::AlignCenter);
    dialogCurrent->setStyleSheet("QLabel{color:white;}");
    dialogCurrent->show();

    dialogInfo = new QLabel(game);
    dialogInfo->setFixedSize(dialogWidth,dialogHeight-dialogCurrent->height());
    dialogInfo->move(WindowWidth/2-dialogWidth/2,dialogCurrent->height());
    dialogInfo->setWordWrap(true);
    dialogInfo->setText("Des ennemies approchent !");
    dialogInfo->setAlignment(Qt::AlignCenter);
    dialogInfo->show();

    dialogSelection = new QLabel(game);
    dialogSelection->setFixedSize(dialogWidth,dialogHeight);
    dialogSelection->move(WindowWidth/2-dialogWidth/2,WindowHeight-dialogHeight);
    dialogSelection->show();

    int boutonHeight(int(80/ratio));
    int boutonWidth(int(300/ratio));
    espacementBoutonH = (int((dialogWidth-boutonWidth*2)/3));
    espacementBoutonV = (int((dialogHeight-boutonHeight*2)/3));

    ///Création d'un style pour les boutons.
    QString styleBouton = "QPushButton {color:white; background-color: #302514;"
                          "border-style: outset; border-width: 2px;"
                          "border-radius: 10px; border-color: beige;"
                          "font: bold 14px; min-width: 10em; padding: 6px;}"
                          "QPushButton:pressed {color:white; background-color: #000000;"
                          "border-style: inset;}";

    QString styleBoutonRond = "QPushButton {color:white; background-color: #302514;"
                              "border-style: outset; border-width: 1px;"
                              "border-radius: 25px; border-color: beige;"
                              "font: bold 14px; padding: 6px;}"
                              "QPushButton:pressed {color:white; background-color: #000000;"
                              "border-style: inset;}";

    ///Création des 7 boutons de base pour l'interface.
    attack = new QPushButton("Attaquer", game);
    attack->setFixedSize(boutonWidth,boutonHeight);
    attack->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonV);
    attack->setStyleSheet(styleBouton);
    sorts = new QPushButton("Sorts", game);
    sorts->setFixedSize(boutonWidth,boutonHeight);
    sorts->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonV);
    sorts->setStyleSheet(styleBouton);
    objet = new QPushButton("Objets", game);
    objet->setFixedSize(boutonWidth,boutonHeight);
    objet->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonV*2+boutonHeight);
    objet->setStyleSheet(styleBouton);
    fuite = new QPushButton("Fuir", game);
    fuite->setFixedSize(boutonWidth,boutonHeight);
    fuite->setStyleSheet(styleBouton);

    int tailleBouton(50);

    retour = new QPushButton("↪", game);
    retour->setFixedSize(tailleBouton,tailleBouton);
    retour->move(dialogSelection->x()-espacementBoutonV-tailleBouton,WindowHeight-tailleBouton-espacementBoutonV);
    retour->show();
    retour->setStyleSheet(styleBoutonRond);
    next = new QPushButton("<", game);
    next->setFixedSize(tailleBouton,tailleBouton);
    next->move(dialogSelection->x()+dialogWidth+espacementBoutonV,WindowHeight-tailleBouton-espacementBoutonV);
    next->show();
    next->setStyleSheet(styleBoutonRond);
    previous = new QPushButton(">", game);
    previous->setFixedSize(tailleBouton,tailleBouton);
    previous->move(dialogSelection->x()+dialogWidth+espacementBoutonV*2+tailleBouton,WindowHeight-tailleBouton-espacementBoutonV);
    previous->show();
    previous->setStyleSheet(styleBoutonRond);

    ///Utilisation d'un QSignalMapper pour connecter un signal sans paramètre à un slot avec paramètre.
    signalMapperSkill = new QSignalMapper(this);
    QObject::connect(signalMapperSkill, SIGNAL(mapped(int)), this, SLOT(choixSkill(int)));
    signalMapperObjet = new QSignalMapper(this);
    QObject::connect(signalMapperObjet, SIGNAL(mapped(int)), this, SLOT(choixObjet(int)));

    QObject::connect(attack, SIGNAL(clicked()), this, SLOT(callAttack()));
    QObject::connect(sorts, SIGNAL(clicked()), this, SLOT(showSkill()));
    QObject::connect(objet, SIGNAL(clicked()), this, SLOT(showObjet()));
    QObject::connect(fuite, SIGNAL(clicked()), game, SLOT(ShowFrame()));
    QObject::connect(fuite, SIGNAL(clicked()), music, SLOT(stop()));

    int espacementBoutonVChoix(int((dialogHeight-boutonHeight*2)/5));

    for (int i = 0; i < 8; i=i+1)
    {
        selectionObjet[i] = new QPushButton("objet",game);
        selectionObjet[i]->setFixedSize(boutonWidth,int(boutonHeight*0.5));
        selectionObjet[i]->setStyleSheet(styleBouton);
        signalMapperObjet->setMapping(selectionObjet[i], i);
        connect(selectionObjet[i], SIGNAL(clicked()), signalMapperObjet, SLOT(map()));

        selectionSkill[i] = new QPushButton("attaque",game);
        selectionSkill[i]->setFixedSize(boutonWidth,int(boutonHeight*0.5));
        selectionSkill[i]->setStyleSheet(styleBouton);
        signalMapperSkill->setMapping(selectionSkill[i], i);
        connect(selectionSkill[i], SIGNAL(clicked()), signalMapperSkill, SLOT(map()));

        if(i<4)
        {
            selectionObjet[i]->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonVChoix*(i+1)+int(boutonHeight*0.5*i));
            selectionSkill[i]->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonVChoix*(i+1)+int(boutonHeight*0.5*i));
        }
        else
        {
            selectionObjet[i]->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonVChoix*(i-4+1)+int(boutonHeight*0.5*(i-4)));
            selectionSkill[i]->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonVChoix*(i-4+1)+int(boutonHeight*0.5*(i-4)));
        }
    }

    signalMapperEntity = new QSignalMapper(this);
    QObject::connect(signalMapperEntity, SIGNAL(mapped(int)), this, SLOT(choixEntity(int)));

    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        selectionEntity[i] = new QPushButton("Entity",game);
        selectionEntity[i]->setFixedSize(boutonWidth,boutonHeight);
        selectionEntity[i]->setStyleSheet(styleBouton);
        signalMapperEntity->setMapping(selectionEntity[i], i);
        connect(selectionEntity[i], SIGNAL(clicked()), signalMapperEntity, SLOT(map()));

        if(i<2)
        {
            selectionEntity[i]->move(dialogSelection->x()+espacementBoutonH,dialogSelection->y()+espacementBoutonV*(i+1)+boutonHeight*i);
        }
        else
        {
            selectionEntity[i]->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonV*(2-i+1)+boutonHeight*(2-i));
        }
    }

    ok = new QPushButton("Combattre !", game);
    ok->setFixedSize(boutonWidth,boutonHeight);
    ok->setStyleSheet(styleBouton);
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(nextTurn()));

    ok->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.25)-int(boutonHeight*0.5));
    fuite->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.75)-int(boutonHeight*0.5));

    ok->show();
    fuite->show();

    okObjet = new QPushButton("Utiliser !", game);
    okObjet->setFixedSize(boutonWidth,boutonHeight);
    okObjet->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.5)-int(boutonHeight*0.5));
    okObjet->setStyleSheet(styleBouton);

    okSkill = new QPushButton("Sélectionner !", game);
    okSkill->setFixedSize(boutonWidth,boutonHeight);
    okSkill->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.5)-int(boutonHeight*0.5));
    okSkill->setStyleSheet(styleBouton);
    QObject::connect(okSkill, SIGNAL(clicked()), this, SLOT(callSkill()));
}

////////////////////////////////////////////////////////
///                                                  ///
///                   Fonctions                      ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn void::BattleFrame::nextTurn()

    Fonction appelée à chaque nouveau tour, elle gère le tour de la manière suivante :

        1) Regarde le combat est terminé
            - Si oui, affiche un texte de fin et le bouton pour quitter le combat.
            - Si non, passe au 2)

        2) Appel de différentes méthodes pour mettre à jours certaines informations.

        3) Regarde si l'entité qui est en train de jouer est un Mob ou un Héro.
            - Si Mob, affiche le bouton pour jouer automatiquement le tour du Mob (via l'IA).
            - Si Héro, passe au 4)

        4) Appel de la méthode ShowSelection() qui va afficher les différentes options d'action proposées au joueur.

*/
void::BattleFrame::nextTurn()
{
    if(!fight->isEnded())
    {
        ok->hide();
        ok->move(dialogSelection->x()+int(dialogSelection->width()*0.5)-int(ok->width()*0.5),dialogSelection->y()+int(dialogSelection->height()*0.5)-int(ok->height()*0.5));
        fuite->hide();
        fuite->move(dialogSelection->x()+espacementBoutonH*2+fuite->width(),dialogSelection->y()+espacementBoutonV*2+fuite->height());

        current = fight->nextPlayer();

        updateCurrentPlayer();

        for (int i=0 ; i < Fight::nb_e ; i=i+1)
        {
            selectionEntity[i]->hide();
        }

        if(dynamic_cast<Mob*>(current) != nullptr)
        {
            QObject::disconnect(retour, SIGNAL(clicked()), this, SLOT(showSelection()));
            skillNumber = (dynamic_cast<Mob*>(current))->chooseMove();
            hited=fight->target(dynamic_cast<Mob*>(current), skillNumber);
            playTurn();
        }
        else if(dynamic_cast<Hero*>(current) != nullptr)
        {
            QObject::connect(retour, SIGNAL(clicked()), this, SLOT(showSelection()));
            updateTurnInfo();
            showSelection();
        }
        else
        {
            std::cout << "Erreur lors de nextPlayer()" << endl;
        }
    }
    else{
        if(fight->mobsWin())
        {
            dialogCurrent->setText("Defaite");
            QObject::disconnect(fuite, SIGNAL(clicked()), game, SLOT(ShowFrame()));
            QObject::connect(fuite, SIGNAL(clicked()), game, SLOT(CreateGameOverFrame()));
        }
        else
        {
            dialogCurrent->setText("Victoire");
            QObject::connect(fuite, SIGNAL(clicked()), game, SLOT(ShowFrame()));
        }
        dialogInfo->setText("C'est très la fin !");
        ok->hide();
        fuite->setText("Fin");
        fuite->move(dialogSelection->x()+int(dialogSelection->width()*0.5)-int(fuite->width()*0.5),dialogSelection->y()+int(dialogSelection->height()*0.5)-int(fuite->height()*0.5));
        fuite->show();
    }

}

/*!
    \fn void::BattleFrame::updateUI()

    Fonction qui met à jours tous les UI de toutes les entités.
*/
void::BattleFrame::updateUI()
{
    ok->setText("OK");

    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        if(teamUI[i] != nullptr)
        {
            teamUI[i]->Update();
        }
        if(ennemyUI[i] != nullptr)
        {
            ennemyUI[i]->Update();
        }
    }
}

/*!
    \fn void::BattleFrame::playTurn()

    Fonction qui joue le tour de l'entité en fonction de l'action choisie par le joueur ou l'IA.
*/
void::BattleFrame::playTurn()
{
    QObject::disconnect(retour, SIGNAL(clicked()), this, SLOT(showSelection()));

    updateCurrentPlayer();

    dialogInfo->setText(QString::fromStdString(current->getSkillSummary(skillNumber)));
    updateUI();
    if(skillNumber==-1)
    {
        attackEntity(current);
    }
    else
    {
        skillEntity(current);
        playSkillEffect();
    }

    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        selectionEntity[i]->hide();
    }
    QObject::connect(current->getSpriteAttack(), SIGNAL(done()), this, SLOT(playDamage()));
    QObject::connect(current->getSpriteSkill(), SIGNAL(done()), this, SLOT(playDamage()));
}

/*!
    \fn void BattleFrame::playDamage()

    Fonction qui permet d'appeler une méthode pour afficher le sprite de dégât pour chaque entité qui a subie des dommages.
*/
void BattleFrame::playDamage()
{
    resetCurrentSprite();
    if(!current->hasSkillMiss(skillNumber))
    {
        if(dynamic_cast<Attack*>(current->getMove(skillNumber)) != nullptr)
        {
            for (unsigned long long i=0 ; i < hited.size() ; i++)
            {
                damageEntity(hited[i],i);
            }
        }
    }
    ok->show();
}

/*!
    \fn void BattleFrame::playSkillEffect()

    Fonction qui permet d'appeler une méthode pour afficher le sprite de sort sur chaque entité qui a subie les effets de ce sort.
*/
void BattleFrame::playSkillEffect()
{
    if(!current->hasSkillMiss(skillNumber))
    {
        for (unsigned long long i=0 ; i < hited.size() ; i++)
        {
            effectEntity(hited[i],i);
        }
    }
}

/*!
    \fn BattleFrame::callAttack()

    Fonction qui se déclenche lorsque le joueur souhaite attaquer, elle affiche les différentes entités que le joueur peut cibler avec
    cette attaque.
*/
void BattleFrame::callAttack()
{
    dialogInfo->setText("Qui voulez vous cibler ?");
    dialogCurrent->setText("Attaque");

    attack->hide();
    sorts->hide();
    objet->hide();
    fuite->hide();

    skillNumber=-1;

    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        mob=fight->getMobs()[i];

        if(mob != nullptr)
        {
            if(mob->isAlive())
            {
                selectionEntity[i]->setText(QString::fromStdString(mob->getName()));
                selectionEntity[i]->show();
            }
        }
    }


}

/*!
    \fn void BattleFrame::updateCurrentPlayer()

    Fonction qui met à jour et affiche le nom de l'entité en train de jouer.
*/
void BattleFrame::updateCurrentPlayer()
{
    dialogCurrent->setText(QString::fromStdString(current->getName()));
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::updateTurnInfo()
{
    dialogInfo->setText("Que voulez vous faire ?");
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::showSelection()
{
    updateTurnInfo();
    updateCurrentPlayer();
    for (int i = 0; i < 8; i=i+1)
    {
        selectionObjet[i]->hide();
        selectionSkill[i]->hide();
    }
    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        selectionEntity[i]->hide();
    }
    okSkill->hide();

    updateTurnInfo();

    attack->show();
    sorts->show();
    objet->show();
    fuite->show();
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::showObjet()
{
    attack->hide();
    sorts->hide();
    objet->hide();
    fuite->hide();

    for (int i = 0; i<inventory->getSize(); i=i+1)
    {
        std::cout<<i<<endl;
        selectionObjet[i]->setText(QString::fromStdString(inventory->getItem(i).getName()));
        selectionObjet[i]->show();
    }
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::showSkill()
{
    dialogInfo->setText("Liste des sorts");

    attack->hide();
    sorts->hide();
    objet->hide();
    fuite->hide();

    for (int i = 0; i < current->getSkillsSize() ; i=i+1)
    {
        selectionSkill[i]->setText(QString::fromStdString(current->getMove(i)->getName()));
        selectionSkill[i]->show();
    }
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::choixSkill(int i)
{
    dialogInfo->setText(QString::fromStdString(current->getMove(i)->getText()+"<br> Cout : "+to_string(current->getMove(i)->getMpCost()))+" MP");
    dialogCurrent->setText(QString::fromStdString(current->getMove(i)->getName()));
    skillNumber=i;
    if(current->getMp()>=current->getMove(skillNumber)->getMpCost())
    {
        okSkill->show();
    }
    else
    {
        okSkill->hide();
        dialogInfo->setText(dialogInfo->text()+" ✖ <b>MP insuffisants !</b>");
    }
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::choixObjet(int i)
{
    dialogInfo->setText(QString::fromStdString(inventory->getItem(i).getText()));
    dialogCurrent->setText(QString::fromStdString(inventory->getItem(i).getName()));
    skillNumber=i;
    //okObject->show();
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::callSkill()
{
    dialogInfo->setText("Qui voulez vous cibler ?");
    okSkill->hide();
    for (int i = 0; i < 8; i=i+1)
    {
        selectionSkill[i]->hide();
    }
    if(current->getMove(skillNumber)->getRange()==one_ally)
    {
        for (int i=0 ; i < Fight::nb_e ; i=i+1)
        {
            allie=fight->getHeroes()[i];

            if(allie != nullptr)
            {
                if(allie->isAlive())
                {
                    selectionEntity[i]->setText(QString::fromStdString(allie->getName()));
                    selectionEntity[i]->show();
                }
            }
        }
    }
    else if(current->getMove(skillNumber)->getRange()==one_enemy)
    {
        for (int i=0 ; i < Fight::nb_e ; i=i+1)
        {
            mob=fight->getMobs()[i];

            if(mob != nullptr)
            {
                if(mob->isAlive())
                {
                    selectionEntity[i]->setText(QString::fromStdString(mob->getName()));
                    selectionEntity[i]->show();
                }
            }
        }
    }
    else
    {
        hited=fight->target(dynamic_cast<Hero*>(current), skillNumber);
        playTurn();
    }
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::choixEntity(int i)
{
    hited=fight->target(dynamic_cast<Hero*>(current), skillNumber, i);
    playTurn();
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::killEntity(Entity *s)
{
    s->getSpriteNormal()->hide();
    dynamic_cast<Hero*>(s)->getSpriteKilled()->show();
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::damageEntity(Entity *s, unsigned long long i)
{
    s->getSpriteNormal()->hide();
    s->getSpriteDamage()->show();
    s->getSpriteDamage()->play(i);
    QObject::connect(hited[i]->getSpriteDamage(), SIGNAL(reset(unsigned long long)), this, SLOT(resetHitedSprite(unsigned long long)));
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::effectEntity(Entity *s, unsigned long long i)
{
    spriteEffect[i]=current->getMove(skillNumber)->getSprite();
    spriteEffect[i]->setPos(QPointF(s->getSpriteNormal()->x()+s->getSpriteNormal()->getWidth()/2-spriteEffect[i]->getWidth()/2,s->getSpriteNormal()->y()+s->getSpriteNormal()->getHeight()/2-spriteEffect[i]->getHeight()/2));
    scene->addItem(spriteEffect[i]);
    dynamic_cast<SpriteUnique*>(spriteEffect[i])->play(i);

    QObject::connect(dynamic_cast<SpriteUnique*>(spriteEffect[i]), SIGNAL(reset(unsigned long long)), this, SLOT(stopEffect(unsigned long long)));
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::stopEffect(unsigned long long i)
{
    spriteEffect[int(i)]->hide();
    cout << i << endl;
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::resetHitedSprite(unsigned long long i)
{
    hited[i]->getSpriteDamage()->hide();
    if(!hited[i]->isAlive()){
        if(dynamic_cast<Hero*>(hited[i]) != nullptr)
        {
            dynamic_cast<Hero*>(hited[i])->getSpriteKilled()->show();
        }
        else
        {
            dynamic_cast<Mob*>(hited[i])->getSpriteKilled()->show();
            dynamic_cast<Mob*>(hited[i])->getSpriteKilled()->play(i);
            QObject::connect(dynamic_cast<Mob*>(hited[i])->getSpriteKilled(), SIGNAL(reset(unsigned long long)), this, SLOT(hideSprite(unsigned long long)));

        }
    }
    else
    {
        hited[i]->getSpriteNormal()->show();
    }
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::hideSprite(unsigned long long i)
{
    hited[i]->getSpriteKilled()->hide();
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::attackEntity(Entity *s)
{
    s->getSpriteNormal()->hide();
    s->getSpriteAttack()->show();
    s->getSpriteAttack()->play(NULL);
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::skillEntity(Entity *s)
{
    s->getSpriteNormal()->hide();
    s->getSpriteSkill()->show();
    s->getSpriteSkill()->play(NULL);
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::deleteEntity(Entity *s)
{
    Q_UNUSED(s);
}

/*!
    \fn void BattleFrame::updateTurnInfo()

    Fonction qui affiche un texte particulier.
*/
void BattleFrame::resetCurrentSprite()
{
    current->getSpriteAttack()->hide();
    current->getSpriteSkill()->hide();
    current->getSpriteNormal()->show();
}



