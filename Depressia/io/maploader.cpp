#include "maploader.h"
#include "dialogloader.h"

using namespace std;

MapLoader::MapLoader()
{

}

Map MapLoader::generate()
{
    Map map;
    return map;
}

Map MapLoader::generate(string path)
{
    ifstream file(path);
    string line, name, text, image, et, e;
    vector<MapElement> mapElements;
    MapElement mapElement;
    unsigned int nb_elements;
    unsigned int transit;
    vector<unsigned int> rights, ups, lefts, downs;

    if(file)
    {
        getline(file,line);
        nb_elements = unsigned (stoi(line));

        for(unsigned i=0 ; i<nb_elements ; i++)
        {
            getline(file,name);
            getline(file,text);
            getline(file,image);
            getline(file,et);

            if(et == "none")
                mapElement = MapElement(name, text, image, Event());

            else if(et == "dialog")
            {
                getline(file,e);
                mapElement = MapElement(name, text, image, Event(dialog, DialogLoader::generate(e)));
            }
            else
            {
                cout << "ERREUR : type d'évènement non reconnu :" << e << endl;
                mapElement = MapElement(name, text, image, Event());

            }



            mapElements.push_back(mapElement);

        }

        for(unsigned int j=0 ; j<nb_elements ; j++)
        {
            file >> transit;
            rights.push_back(transit);
        }

        for(unsigned int k=0 ; k<nb_elements ; k++)
        {
            file >> transit;
            ups.push_back(transit);
        }

        for(unsigned int l=0 ; l<nb_elements ; l++)
        {
            file >> transit;
            lefts.push_back(transit);
        }

        for(unsigned int m=0 ; m<nb_elements ; m++)
        {
            file >> transit;
            downs.push_back(transit);
        }


        return Map(mapElements, rights, ups, lefts, downs);

    }

    else
    {
        cout << "ERREUR : fichier de création de map introuvable" << endl;
        return Map();
    }
}
