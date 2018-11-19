#ifndef EVENT_H
#define EVENT_H

#include"logic/entities/entity.h"
#include"logic/events/dialog.h"

enum EventType {none, dialog, video, item_found, fight, final_screen};

class Event
{
public:
    Event();
    Event(EventType et, Dialog d);
    Event(EventType et, std::string v);
    ~Event();

    EventType getEventType();
    Dialog getDialog();
    std::string getVideo();

private:
    EventType eventType;
    Dialog dialog;
    std::string video;
};

#endif // EVENT_H
