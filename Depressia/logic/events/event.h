#ifndef EVENT_H
#define EVENT_H

#include"logic/entities/entity.h"
#include"logic/events/dialog.h"
#include"logic/items/item.h"

enum EventType {none, dialog, video, item_found, fight, final_screen};

class Event
{
public:
    Event();
    Event(Dialog d);
    Event(std::string v);
    Event(Item i);
    ~Event();

    EventType getEventType();
    Dialog getDialog();
    std::string getVideo();
    Item getItem();

private:
    EventType eventType;
    Dialog dial;
    std::string vid;
    Item itm;
};

#endif // EVENT_H
