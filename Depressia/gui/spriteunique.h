#ifndef SPRITEUNIQUE_H
#define SPRITEUNIQUE_H

#include "spritetemplate.h"

class SpriteUnique : public SpriteTemplate
{
        Q_OBJECT

signals:
    void reset(unsigned long long);


public slots:
    void nextFrame();
    void play(unsigned long long);

public:
    SpriteUnique();

    SpriteUnique(int nb, int w, int h, std::string s);

    unsigned long long entityNumber;
};

#endif // SPRITEUNIQUE_H
