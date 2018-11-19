#include "itemloader.h"

using namespace std;

ItemLoader::ItemLoader()
{

}

Item ItemLoader::generate()
{
    return Item();
}

Item ItemLoader::generate(string path)
{
    string n, t, i;
    ifstream file(path);

    if(file)
    {
        getline(file,n);
        getline(file,t);
        getline(file,i);

        return Item(n,t,i);
    }

    else
    {
        cout << "ERREUR : item path introuvable : " << path << endl;
        return Item();
    }
}
