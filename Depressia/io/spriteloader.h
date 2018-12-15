#pragma once

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

//#include "gui/sprite.h"
#include "gui/spriteloop.h"
#include "gui/spriteunique.h"
#include <fstream>
#include<iostream>

class SpriteLoader
{
private:
    SpriteTemplate* list[5];
public:
    SpriteLoader();
    //Sprite* generate();
    static SpriteTemplate* generate(std::string path);
    //static Sprite* generate(std::string path);
};

#endif // SPRITELOADER_H
