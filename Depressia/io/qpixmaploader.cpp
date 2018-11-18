#include "qpixmaploader.h"

using namespace std;

QPixmapLoader::QPixmapLoader()
{

}

QPixmap QPixmapLoader::getQPixmap(string path)
{
    ifstream file(path);
    if(file)
        return QPixmap(QString::fromStdString(path));
    else
    {
        cout << "ERREUR : l'image souhaitée n'existe pas" << endl;
        return QPixmap();
    }
}
