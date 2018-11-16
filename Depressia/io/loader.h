#ifndef LOADER_H
#define LOADER_H

#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<QPixmap>
#include<QString>

#include"logic/entities/entity.h"
#include"logic/events/event.h"
#include"logic/items/item.h"
#include"logic/world/map.h"

class Loader
{
public:
    Loader();
    static QPixmap getQPixmap(std::string path);
    std::vector<Skill> generate_skills(std::string path);

    /*
    std::vector<Entity> generate_entities(std::string path);
    std::vector<Item> generate_items(std::string path);
    std::vector<Event> generate_events(std::string path);
    Map generate_map(std::string path);
    */
};

#endif // DATALOADER_H
