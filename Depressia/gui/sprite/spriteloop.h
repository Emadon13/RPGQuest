#ifndef SPRITELOOP_H
#define SPRITELOOP_H


#include "spritetemplate.h"

class SpriteLoop : public SpriteTemplate
{
        Q_OBJECT

public slots:
    void nextFrame();

public:
    SpriteLoop();

    SpriteLoop(int nb, int w, int h, std::string s);
};

#endif // SPRITELOOP_H
