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
#include "gui/sprite.h"
#include "gui/clickable/clickablelabel.h"
#include "gui/frame/characterui.h"
#include "gui/frame/enemyui.h"
#include "gui/spriteloop.h"
#include "gui/spriteunique.h"
#include "io/spriteloader.h"

BattleFrame::BattleFrame(GameWindow *g) : QObject()
{
    game=g;

    fight=((dynamic_cast<Fight*>(game->GetGame()->getMap()->getCurrentPosition().getEvent())));

    playlist = new QMediaPlaylist();
    playlist->addMedia(*fight->getMusic());
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    int WindowWidth(game->GetGame()->getWindowWidth());
    int WindowHeight(game->GetGame()->getWindowHeight());

    double ratio(game->GetGame()->getRatio());

    QLabel *back = new QLabel(game);
    back->setPixmap(QPixmap("../ressources/images/hud/background-battle7.png").scaled(WindowWidth,WindowHeight));
    back->setFixedSize(WindowWidth,WindowHeight);
    back->move(0,0);
    back->show();

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
            cout << mob->getSpriteAttack() << endl;
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

    int dialogWidth(int(WindowWidth*0.4));
    int dialogHeight(int(WindowHeight*0.19));

    dialogInfo = new QLabel(game);
    dialogInfo->setPixmap(QPixmap("../ressources/images/hud/jaugeHP.png").scaled(dialogWidth,dialogHeight));
    dialogInfo->setFixedSize(dialogWidth,dialogHeight);
    dialogInfo->move(WindowWidth/2-dialogWidth/2,0);
    dialogInfo->setWordWrap(true);
    dialogInfo->setText("La Grande Tata et son esclave vous défient");
    dialogInfo->show();

    dialogSelection = new QLabel(game);
    dialogSelection->setPixmap(QPixmap("../ressources/images/hud/jaugeHP.png").scaled(dialogWidth,dialogHeight));
    dialogSelection->setFixedSize(dialogWidth,dialogHeight);
    dialogSelection->move(WindowWidth/2-dialogWidth/2,WindowHeight-dialogHeight);
    dialogSelection->show();

    dialogCurrent = new QLabel(game);
    dialogCurrent->setPixmap(QPixmap("../ressources/images/hud/jaugeMP.png").scaled(dialogWidth,dialogHeight));
    dialogCurrent->setFixedSize(int(dialogWidth*0.2),int(dialogHeight*0.2));
    dialogCurrent->move(WindowWidth/2-dialogWidth/2,0);
    dialogCurrent->show();

    int boutonHeight(int(80/ratio));
    int boutonWidth(int(300/ratio));
    espacementBoutonH = (int((dialogWidth-boutonWidth*2)/3));
    espacementBoutonV = (int((dialogHeight-boutonHeight*2)/3));

    QString styleBouton = "QPushButton {background-color: cyan;"
                          "border-style: outset; border-width: 2px;"
                          "border-radius: 10px; border-color: beige;"
                          "font: bold 14px; min-width: 10em; padding: 6px;}"
                          "QPushButton:pressed {background-color: rgb(224, 0, 0);"
                          "border-style: inset;}";

    QString styleBoutonRond =   "QPushButton { background-color: white;"
                                "border-style: solid;"
                                "border-width:1px;"
                                "border-radius:25px;"
                                "border-color: red;}";

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

    signalMapperSkill = new QSignalMapper(this);
    QObject::connect(signalMapperSkill, SIGNAL(mapped(int)), this, SLOT(choixSkill(int)));

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

        if(dynamic_cast<Mob*>(current) != NULL)
        {
            QObject::disconnect(retour, SIGNAL(clicked()), this, SLOT(showSelection()));
            skillNumber = (dynamic_cast<Mob*>(current))->chooseMove();
            hited=fight->target(dynamic_cast<Mob*>(current), skillNumber);
            playTurn();
        }
        else if(dynamic_cast<Hero*>(current) != NULL)
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
        dialogCurrent->setText("");
        dialogInfo->setText("C'est très la fin !");
        ok->hide();
        fuite->setText("Fin");
        fuite->move(dialogSelection->x()+int(dialogSelection->width()*0.5)-int(fuite->width()*0.5),dialogSelection->y()+int(dialogSelection->height()*0.5)-int(fuite->height()*0.5));
        fuite->show();
    }

}

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

void::BattleFrame::playTurn()
{
    dialogInfo->setText(QString::fromStdString(current->getSkillSummary(skillNumber)));
    updateUI();
    if(skillNumber==-1)
    {
        attackEntity(current);
    }
    else
    {
        skillEntity(current);
    }

    for (int i=0 ; i < Fight::nb_e ; i=i+1)
    {
        selectionEntity[i]->hide();
    }

    QObject::connect(current->getSpriteAttack(), SIGNAL(done()), this, SLOT(playDamage()));
    QObject::connect(current->getSpriteSkill(), SIGNAL(done()), this, SLOT(playDamage()));
}

void BattleFrame::playDamage()
{
    if(!current->hasSkillMiss(skillNumber))
    {
        for (unsigned long long i=0 ; i < hited.size() ; i++)
        {
            damageEntity(hited[i]);
        }
    }
    ok->show();
}

void BattleFrame::callAttack()
{
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
            selectionEntity[i]->setText(QString::fromStdString(mob->getName()));
            selectionEntity[i]->show();
        }
    }


}

void::BattleFrame::updateCurrentPlayer()
{
    dialogCurrent->setText(QString::fromStdString(current->getName()));
}

void BattleFrame::updateTurnInfo()
{
    dialogInfo->setText("Que voulez vous faire ?");
}

void BattleFrame::showSelection()
{
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

void BattleFrame::showObjet()
{
    attack->hide();
    sorts->hide();
    objet->hide();
    fuite->hide();

    for (int i = 0; i < 8; i=i+1)
    {
        selectionObjet[i]->show();
    }
}

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

void BattleFrame::choixSkill(int i)
{
    dialogInfo->setText(QString::fromStdString(current->getMove(i)->getText()));
    okSkill->show();
    skillNumber=i;
}

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
                selectionEntity[i]->setText(QString::fromStdString(allie->getName()));
                selectionEntity[i]->show();
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
                selectionEntity[i]->setText(QString::fromStdString(mob->getName()));
                selectionEntity[i]->show();
            }
        }
    }
    else
    {
        hited=fight->target(dynamic_cast<Hero*>(current), skillNumber);
        playTurn();
    }
}

void BattleFrame::choixEntity(int i)
{
    hited=fight->target(dynamic_cast<Hero*>(current), skillNumber, i);
    playTurn();
}

void BattleFrame::killEntity(Entity *s)
{
    s->getSpriteNormal()->hide();
    s->getSpriteKilled()->show();
}

void BattleFrame::damageEntity(Entity *s)
{
    s->getSpriteNormal()->hide();
    s->getSpriteDamage()->show();
    s->getSpriteDamage()->play();
}

void BattleFrame::attackEntity(Entity *s)
{
    s->getSpriteNormal()->hide();
    s->getSpriteAttack()->show();
    s->getSpriteAttack()->play();
}

void BattleFrame::skillEntity(Entity *s)
{
    s->getSpriteSkill()->hide();
    s->getSpriteSkill()->show();
    s->getSpriteSkill()->play();
}

void BattleFrame::deleteEntity(Entity *s)
{

}

void BattleFrame::setCorrectSprite()
{

}



