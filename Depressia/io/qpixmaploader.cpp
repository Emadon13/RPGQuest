#include "qpixmaploader.h"

using namespace std;

QPixmapLoader::QPixmapLoader()
{

}

QPixmap QPixmapLoader::getQPixmap(string path)
{
    return QPixmap(QString::fromStdString(path));
}
