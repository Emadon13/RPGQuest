#ifndef QPIXMAPLOADER_H
#define QPIXMAPLOADER_H

#include"io/loader.h"

class QPixmapLoader : public Loader
{
public:
    QPixmapLoader();
    static QPixmap getQPixmap(std::string path);

};

#endif // QPIXMAPLOADER_H
