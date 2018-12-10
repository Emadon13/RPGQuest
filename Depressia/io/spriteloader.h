#pragma once

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include "gui/sprite.h"
#include <fstream>
#include<iostream>

class SpriteLoader
{
public:
    SpriteLoader();
    Sprite* generate();
    static Sprite* generate(std::string path);
};

#endif // SPRITELOADER_H
