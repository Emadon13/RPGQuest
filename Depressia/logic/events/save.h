#ifndef SAVE_H
#define SAVE_H

#include "logic/events/event.h"
#include "io/gameloader.h"

class Save : public Event
{
public:
    Save();

    void heal(Team team);
    void save(Game game);
};

#endif // SAVE_H
