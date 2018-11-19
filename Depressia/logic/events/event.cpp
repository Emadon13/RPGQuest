#include "event.h"

using namespace std;

Event::Event():
    eventType(none)
{

}

Event::Event(EventType et, Dialog d):
    eventType(et)
{
    dialog = d;
}

Event::Event(EventType et, string v):
    eventType(et),
    video(v)
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
    return dialog;
}
