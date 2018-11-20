#include "video.h"

using namespace std;

Video::Video():
    video("")
{

}

Video::Video(string v):
    video(v)
{

}

string Video::getVideo()
{
    return video;
}
