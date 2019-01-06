#include "spriteloop.h"
#include <iostream>

////////////////////////////////////////////////////////
///                                                  ///
///                   SpriteLoop                     ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class SpriteLoop

    Cette classe
*/

SpriteLoop::SpriteLoop(int nb, int w, int h, std::string s) : SpriteTemplate (nb, w, h, s)
{
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

void SpriteLoop::nextFrame()
{
    currentFrame += width;
    if (currentFrame >= width*nbFrame) currentFrame = 0;
    this->update(0,0,width,height);
}


