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
            teamSprite[i] = allie->getSprite();
            std::cout << teamSprite[i] << std::endl;
            std::cout << allie->getSprite() << std::endl;
            if(i%2==0) teamSprite[i]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2))));
            else teamSprite[i]->setPos(QPointF(int(((WindowWidth*0.5)+espacementSprite*(i)+espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            teamSprite[i]->setToolTip(QString::fromStdString(allie->getName()));

            scene->addItem(teamSprite[i]);

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
            ennemySprite[i] = mob->getSprite();
            if(i%2==1) ennemySprite[i]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2))));
            else ennemySprite[i]->setPos(QPointF(int(((WindowWidth*0.5)-espacementSprite*(i+1)-espacementMilieu)),int((WindowHeight/2-espacementSprite))));
            ennemySprite[i]->setToolTip(QString::fromStdString(mob->getName()));

            scene->addItem(ennemySprite[i]);

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

    QString styleBouton = "QPushButton {background-color: red;"
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
    //fuite->move(dialogSelection->x()+espacementBoutonH*2+boutonWidth,dialogSelection->y()+espacementBoutonV*2+boutonHeight);
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

    signalMapper = new QSignalMapper(this);
    //QObject::connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(choixSkill(int)));
    //QObject::connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(choixObjet(int)));

    QObject::connect(sorts, SIGNAL(clicked()), this, SLOT(showSkill()));
    QObject::connect(objet, SIGNAL(clicked()), this, SLOT(showObjet()));
    QObject::connect(retour, SIGNAL(clicked()), this, SLOT(showSelection()));
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

    ok = new QPushButton("Combattre !", game);
    ok->setFixedSize(boutonWidth,boutonHeight);
    //ok->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.5)-int(boutonHeight*0.5));
    ok->setStyleSheet(styleBouton);

    ok->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.25)-int(boutonHeight*0.5));
    fuite->move(dialogSelection->x()+int(dialogWidth*0.5)-int(boutonWidth*0.5),dialogSelection->y()+int(dialogHeight*0.75)-int(boutonHeight*0.5));
    ok->show();
    fuite->show();

    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(nextTurn()));

    /*QPushButton *pass = new QPushButton("pass", game);
    pass->setFixedSize(100,100);
    pass->move(90,100);
    pass->show();
    QPushButton *damage = new QPushButton("damage", game);
    damage->setFixedSize(100,100);
    damage->move(200,100);
    damage->show();
    QPushButton *kill = new QPushButton("kill", game);
    kill->setFixedSize(100,100);
    kill->move(300,100);
    kill->show();
    QPushButton *attack = new QPushButton("attack", game);
    attack->setFixedSize(100,100);
    attack->move(400,100);
    attack->show();

    QObject::connect(pass, SIGNAL(clicked()), game , SLOT(CreateGameFrame()));

    QObject::connect(attack, SIGNAL(clicked()), this , SLOT(Attack()));
    QObject::connect(damage, SIGNAL(clicked()), this , SLOT(Damage()));
    QObject::connect(kill, SIGNAL(clicked()), this , SLOT(Kill()));
    */
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

        if(dynamic_cast<Mob*>(current) != NULL)
        {
            skillNumber = (dynamic_cast<Mob*>(current))->chooseMove();
            hited=fight->target(dynamic_cast<Mob*>(current), skillNumber);
            playMobTurn();

        }
        else if(dynamic_cast<Hero*>(current) != NULL)
        {
            //updateTurnInfo();
            //showSelection();
            nextTurn();
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

void::BattleFrame::playMobTurn()
{
    dialogInfo->setText(QString::fromStdString(current->getSkillSummary(skillNumber)));
    updateUI();
    attackEntity(current->getSprite());
    current->hasSkillMiss(skillNumber);

    if(!current->hasSkillMiss(skillNumber))
    {
        for (unsigned long long i=0 ; i < hited.size() ; i++)
        {
            damageEntity(hited[i]->getSprite());
        }
    }

    ok->show();
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
    attack->hide();
    sorts->hide();
    objet->hide();
    fuite->hide();

    for (int i = 0; i < 8; i=i+1)
    {
        selectionSkill[i]->show();
    }
}

void::BattleFrame::Attack()
{
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void::BattleFrame::Damage()
{
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void::BattleFrame::Kill()
{
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(damageEntity(Sprite*)));
     QObject::connect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(killEntity(Sprite*)));
     QObject::disconnect(sprite, SIGNAL(clicked(Sprite*)), this , SLOT(attackEntity(Sprite*)));
}

void BattleFrame::killEntity(Sprite *s)
{
    QObject::connect(s, SIGNAL(killed(Sprite*)), this , SLOT(deleteEntity(Sprite*)));
    s->kill();
}

void BattleFrame::damageEntity(Sprite *s)
{
    s->damage();
}

void BattleFrame::attackEntity(Sprite *s)
{
    s->attack();
}

void BattleFrame::deleteEntity(Sprite *s)
{
    scene->removeItem(s);
}



