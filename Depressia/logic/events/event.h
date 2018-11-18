#ifndef EVENT_H
#define EVENT_H

#include"logic/entities/entity.h"
#include"logic/events/dialog.h"

enum EventType {none, dialog, item_found, fight, final_screen};

class Event
{
public:
    Event();
    Event(EventType et, Dialog d);
    ~Event();

    EventType getEventType();
    Dialog getDialog();

private:
    EventType eventType;
    Dialog dialog;
};

#endif // EVENT_H
