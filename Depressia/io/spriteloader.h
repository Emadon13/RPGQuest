#pragma once

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include "io/loader.h"
#include "gui/sprite.h"

class SpriteLoader
{
public:
    SpriteLoader();
    static std::vector<std::string> generate();
    static std::vector<std::string> generate(std::string path);
};

#endif // SPRITELOADER_H
