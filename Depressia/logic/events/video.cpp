#include "video.h"

using namespace std;

Video::Video():
    Event(),
    video("")
{
    redo = true;
}

Video::Video(string v):
    Event(),
    video(v)
{
    redo = true;
}

string Video::getVideo()
{
    return video;
}
