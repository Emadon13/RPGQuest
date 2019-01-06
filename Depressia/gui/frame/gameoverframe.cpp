#include "gameoverframe.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   GameOverFrame                  ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class GameOverFrame

    Cette classe
*/

GameOverFrame::GameOverFrame(GameWindow *g) : QObject()
{
    game=g;

    clicker = new ClickableLabel(game);
    clicker->setFixedSize(game->GetGame()->getWindowWidth(),game->GetGame()->getWindowHeight());
    clicker->move(0,0);
    clicker->show();

    QObject::connect(clicker, SIGNAL(clicked()), game, SLOT(setPositionAfterLoose()));

}
