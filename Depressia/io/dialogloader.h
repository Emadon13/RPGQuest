#ifndef DIALOGLOADER_H
#define DIALOGLOADER_H

#include"io/loader.h"
#include"logic/events/dialog.h"

class DialogLoader : public Loader
{
public:
    DialogLoader();

    std::vector<Dialog> generate();
    std::vector<Dialog> generate(std::string path);

};

#endif // DIALOGLO ADER_H
