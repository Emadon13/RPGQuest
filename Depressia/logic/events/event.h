#ifndef EVENT_H
#define EVENT_H

#include"logic/entities/entity.h"

enum EventType {none, fight, dialog, item_found, final_screen};

class Event
{
public:
    Event();
    EventType getEventType();
protected:
    EventType eventType;
};

#endif // EVENT_H
