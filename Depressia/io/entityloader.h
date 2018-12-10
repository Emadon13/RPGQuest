#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H

#include "logic/entities/hero.h"
#include "logic/entities/mob.h"
#include "io/skillloader.h"

class EntityLoader
{
public:
    EntityLoader();
    static Entity* generate();
    static Entity* generate(std::string path);
};

#endif // ENTITYLOADER_H
