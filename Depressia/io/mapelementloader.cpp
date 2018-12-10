#include "mapelementloader.h"
#include "io/mapelementloader.h"
#include "io/dialogloader.h"
#include "io/itemloader.h"
#include "logic/events/itemfound.h"
#include "logic/events/save.h"
#include "logic/events/video.h"
#include "logic/events/finalscreen.h"
#include "fightloader.h"

using namespace std;

MapElementLoader::MapElementLoader()
{

}

MapElement MapElementLoader::generate()
{
    return MapElement();
}

MapElement MapElementLoader::generate(Team* t, string path)
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
            return MapElement(name, text, image, NULL);

        else if(et == "save")
            return MapElement(name, text, image, new Save());

        else if(et == "dialog")
        {
            getline(file,e);
            return MapElement(name, text, image, new Dialog(DialogLoader::generate(e)));
        }

        else if(et == "fight")
        {
            getline(file, e);
            return MapElement(name, text,image, new Fight(FightLoader::generate(t,e)));
        }

        else if(et == "video")
        {
            getline(file,e);
            return MapElement(name, text, image, new Video(e));
        }

        else if(et == "item_found")
        {
            getline(file, e);
            return MapElement(name, text, image, new ItemFound(ItemLoader::generate(e)));
        }

        else if(et == "final_screen")
        {
            return MapElement(name, text, image, new FinalScreen());
        }

        else
        {
            cout << "ERREUR : type d'evenement non reconnu :" << e  << " " << name << endl;
            return MapElement(name, text, image, new Event());

        }
    }

    else
    {
        cout << "ERREUR : map element non trouvée : " << line << endl;
        return MapElement();
    }
}
