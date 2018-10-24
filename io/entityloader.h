#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H

#include "logic/entities/entity.h"
#include <string>

class EntityLoader
{
public:
    EntityLoader();

    Entity generate();
    Entity generate(std::string path);
};

#endif // ENTITYLOADER_H
