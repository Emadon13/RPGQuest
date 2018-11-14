#ifndef FIGHT_H
#define FIGHT_H

#include "logic/entities/entity.h"

class Fight
{
public:
    Fight();
    Fight(Entity h[], Entity o[]);


private:
    Entity heroes[];
    Entity opponents[];

    setOrder;
};

#endif // FIGHT_H
