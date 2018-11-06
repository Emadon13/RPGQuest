#ifndef TEST_H
#define TEST_H

#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <logic/entities/entity.h>


class EntityLoader
{
public:
    EntityLoader();
    ~EntityLoader();
    Entity generate();
    Entity generate(std::string path);
};

#endif // TEST_H
