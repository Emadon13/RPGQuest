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
    Event event;
    vector<Event> events(0);
    vector<MapElement> mapElements;
    MapElement mapElement;
    unsigned int nb_elements;
    unsigned int transit;
    vector<unsigned int> rights, ups, lefts, downs;

    if(file)
    {
        file >> nb_elements;

        for(unsigned i=0 ; i<nb_elements ; i++)
        {
            getline(file,name);
            getline(file,text);
            getline(file,image);
            getline(file,et);

            if(et != "none")
                while(et != "end_event")
                {
                    if(et == "dialog")
                    {
                        getline(file,e);
                        event = DialogLoader::generate(e);
                        events.push_back(event);
                        getline(file,et);
                    }
                    else
                    {
                        cout << "ERREUR : type d'évènement non reconnu" << endl;

                    }
                }
            mapElement = MapElement(name, text, image, event);
            mapElements.push_back(mapElement);
            getline(file,line);

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
