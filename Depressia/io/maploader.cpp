#include "maploader.h"
#include "dialogloader.h"

using namespace std;

MapLoader::MapLoader()
{

}

Map MapLoader::generate()
{
    return Map();
}

Map MapLoader::generate(string path)
{
    ifstream file(path);
    string line, mapElementAdd;
    vector<string> mapElementsAdd;
    unsigned int nb_elements;
    unsigned int transit;
    vector<unsigned int> rights, ups, lefts, downs;

    if(file)
    {
        getline(file,line);
        nb_elements = unsigned (stoi(line));

        for(unsigned i=0 ; i<nb_elements ; i++)
        {
            getline(file,mapElementAdd);
            mapElementsAdd.push_back(mapElementAdd);

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


        return Map(mapElementsAdd, rights, ups, lefts, downs);

    }

    else
    {
        cout << "ERREUR : fichier de création de map introuvable" << endl;
        return Map();
    }
}
