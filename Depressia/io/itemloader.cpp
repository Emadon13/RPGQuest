#include "itemloader.h"

using namespace std;

ItemLoader::ItemLoader()
{

}

Item* ItemLoader::generate()
{
    return new Item();
}

Item* ItemLoader::generate(string path)
{
    string n, t, i, type, val;
    ifstream file(path);

    if(file)
    {
        getline(file,n);
        getline(file,t);
        getline(file,i);

        getline(file, type);

        if(type == "hpHeal")
        {
           getline(file, val);
           return new HealItem(n, t, i, stoi(val));
        }

        else if(type == "mpHeal")
        {
           getline(file, val);
           return new RestoreMpItem(n, t, i, stoi(val));
        }

        else if(type=="revive")
        {
            getline(file, val);
            return new ReviveItem(n, t, i, stoi(val));
        }

        return new Item(n,t,i);
    }

    else
    {
        cout << "ERREUR : item path introuvable : " << path << endl;
        return new Item();
    }
}
