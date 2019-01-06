#ifndef EVENT_H
#define EVENT_H



class Event
{
public:
    Event();
    virtual ~Event();
    bool mustRedo();

protected:
    bool redo;

};

#endif // EVENT_H
