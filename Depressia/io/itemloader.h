#ifndef ITEMLOADER_H
#define ITEMLOADER_H

#include"logic/items/item.h"
#include"io/loader.h"

class ItemLoader : public Loader
{
public:
    ItemLoader();

    static Item generate();
    static Item generate(std::string path);
};

#endif // ITEMLOADER_H
