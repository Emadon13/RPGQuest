#ifndef SPRITEUNIQUE_H
#define SPRITEUNIQUE_H

#include "spritetemplate.h"

class SpriteUnique : public SpriteTemplate
{
        Q_OBJECT

public slots:
    void nextFrame();
    void play();

public:
    SpriteUnique();

    SpriteUnique(int nb, int w, int h, std::string s);
};

#endif // SPRITEUNIQUE_H
