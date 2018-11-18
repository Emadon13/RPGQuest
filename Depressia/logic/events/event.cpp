#include "event.h"

Event::Event()
{
    eventType = none;
}

EventType Event::getEventType()
{
    return eventType;
}
