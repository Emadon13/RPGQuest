#pragma once

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include "io/loader.h"
#include "gui/sprite.h"

class SpriteLoader
{
public:
    SpriteLoader();
    static Sprite* generate();
    static Sprite* generate(std::string path);
};

#endif // SPRITELOADER_H
