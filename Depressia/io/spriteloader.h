#pragma once

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

//#include "gui/sprite.h"
#include "gui/sprite/spriteloop.h"
#include "gui/sprite/spriteunique.h"
#include <fstream>
#include<iostream>

class SpriteLoader
{
private:
    SpriteTemplate* list[5];
public:
    SpriteLoader();
    static SpriteTemplate* generate(std::string path);
};

#endif // SPRITELOADER_H
