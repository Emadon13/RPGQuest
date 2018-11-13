#ifndef FIGHT_H
#define FIGHT_H

#include"logic/entities/entity.h"


class Fight
{
public:
    Fight();
    Fight(Entity heroes[], Entity opponents[]);




private:
    std::vector<Entity> heroes;
    std::vector<Entity> monsters;

    void setOrder(Entity fighters[]);

};

#endif // FIGHT_H
