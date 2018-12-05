#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H

#include "io/loader.h"
#include "logic/entities/entity.h"
#include "io/skillloader.h"

class EntityLoader : public Loader
{
public:
    EntityLoader();
    static Entity* generate();
    static Entity* generate(std::string path);
};

#endif // ENTITYLOADER_H
