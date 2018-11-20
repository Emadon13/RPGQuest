#ifndef VIDEO_H
#define VIDEO_H

#include "logic/events/event.h"
#include <string>

class Video : public Event
{
public:
    Video();
    Video(std::string v);
    std::string getVideo();

private:
    std::string video;
};

#endif // VIDEO_H
