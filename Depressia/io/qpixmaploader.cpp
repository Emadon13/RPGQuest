#include "qpixmaploader.h"

using namespace std;

QPixmapLoader::QPixmapLoader()
{

}

QPixmap QPixmapLoader::generate(string path)
{
    ifstream file(path);
    if(file)
        return QPixmap(QString::fromStdString(path));
    else
    {
        return QPixmap();
        throw runtime_error("ERREUR : l'image souhaitée n'existe pas");
    }
}
