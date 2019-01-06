#ifndef ITEMLOADER_H
#define ITEMLOADER_H

#include"logic/items/item.h"
#include"logic/items/debuffcancelitem.h"
#include"logic/items/healitem.h"
#include"logic/items/restorempitem.h"
#include"logic/items/reviveitem.h"
#include"io/loader.h"

class ItemLoader : public Loader
{
public:
    ItemLoader();

    static Item generate();
    static Item generate(std::string path);
};

#endif // ITEMLOADER_H
