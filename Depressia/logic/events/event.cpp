#include "event.h"

using namespace std;

Event::Event():
    redo(false)
{

}


Event::~Event()
{

}

bool Event::mustRedo()
{
    return redo;
}
