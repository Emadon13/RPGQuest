#include "spriteunique.h"

SpriteUnique::SpriteUnique(int nb, int w, int h, std::string s) : SpriteTemplate (nb, w, h, s)
{
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

void SpriteUnique::nextFrame()
{
    currentFrame += width;
    if (currentFrame >= width*nbFrame) {
        emit done();
        timer->stop();
        currentFrame = 0;
        emit reset(entityNumber);
    }
    else this->update(0,0,width,height);
}

void SpriteUnique::play(unsigned long long e){
    entityNumber=e;
    timer->start(100);
}


