#include "finalframe.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   FinalFrame                     ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class FinalFrame

    Cette classe
*/

FinalFrame::FinalFrame(GameWindow *g) : QObject()
{

    game=g;

    clicker = new ClickableLabel(game);
    clicker->setFixedSize(game->GetGame()->getWindowWidth(),game->GetGame()->getWindowHeight());
    clicker->move(0,0);
    clicker->show();

    QObject::connect(clicker, SIGNAL(clicked()), game, SLOT(close()));

}
