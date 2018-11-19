#include "event.h"

using namespace std;

Event::Event():
    eventType(none)
{

}

Event::Event(Dialog d):
    eventType(dialog),
    dial(d)
{

}

Event::Event(string v):
    eventType(video),
    vid(v)
{

}

Event::Event(Item i):
    eventType(item_found),
    itm(i)
{

}

Event::~Event()
{

}

EventType Event::getEventType()
{
    return eventType;
}

Dialog Event::getDialog()
{
    return dial;
}

string Event::getVideo()
{
    return vid;
}

Item Event::getItem()
{
    return itm;
}
