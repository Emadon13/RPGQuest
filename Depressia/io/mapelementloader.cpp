#include "mapelementloader.h"
#include "io/mapelementloader.h"
#include"io/dialogloader.h"
#include"io/itemloader.h"

using namespace std;

MapElementLoader::MapElementLoader()
{

}

MapElement MapElementLoader::generate()
{
    return MapElement();
}

MapElement MapElementLoader::generate(string path)
{
    ifstream file(path);
    string line, name, text, image, et, e;

    if(file)
    {
        getline(file,name);
        getline(file,text);
        getline(file,image);
        getline(file,et);

        if(et == "none")
            return MapElement(name, text, image, Event());

        else if(et == "dialog")
        {
            getline(file,e);
            return MapElement(name, text, image, Event(DialogLoader::generate(e)));
        }

        else if(et == "video")
        {
            getline(file,e);
            return MapElement(name, text, image, Event(e));
        }

        else if(et == "item_found")
        {
            getline(file, e);
            return MapElement(name, text, image, Event(ItemLoader::generate(e)));
        }

        else
        {
            cout << "ERREUR : type d'evenement non reconnu :" << e  << " " << name << endl;
            return MapElement(name, text, image, Event());

        }
    }

    else
    {
        cout << "ERREUR : map element non trouvée : " << line << endl;
        return MapElement();
    }
}
