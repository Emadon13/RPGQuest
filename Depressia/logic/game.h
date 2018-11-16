#ifndef GAME_H
#define GAME_H

#include"io/loader.h"


class Game
{
public:
    Game();

private:
    std::vector<Skill> list_skills;
    std::vector<Item> list_items;
    std::vector<Entity> list_entities;
    std::vector<Event> list_events;
    Map map;

};

#endif // GAME_H
