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
           return HealItem(n, t, i, stoi(val));
        }

        else if(type == "mpHeal")
        {
           getline(file, val);
           return RestoreMpItem(n, t, i, stoi(val));
        }

        else if(type=="revive")
        {
            getline(file, val);
            return ReviveItem(n, t, i, stoi(val));
        }

        return Item(n,t,i);
    }

    else
    {
        cout << "ERREUR : item path introuvable : " << path << endl;
        return Item();
    }
}
