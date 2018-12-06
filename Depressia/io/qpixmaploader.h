#pragma once

#ifndef QPIXMAPLOADER_H
#define QPIXMAPLOADER_H

#include <QPixmap>

class QPixmapLoader
{
public:
    QPixmapLoader();
    static QPixmap generate(std::string path);

};

#endif // QPIXMAPLOADER_H
