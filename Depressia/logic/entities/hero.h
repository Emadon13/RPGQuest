#ifndef HERO_H
#define HERO_H

#include "logic/entities/entity.h"

class Hero : public Entity
{
public:
    Hero();

private:
    int xp;

};

#endif // HERO_H
