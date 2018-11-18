#include "event.h"

Event::Event():
    eventType(none)
{

}

Event::Event(EventType et, Dialog d):
    eventType(et)
{
    dialog = d;
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
