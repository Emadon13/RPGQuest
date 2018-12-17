#include "spriteloader.h"

using namespace std;

SpriteLoader::SpriteLoader()
{

}

SpriteTemplate* SpriteLoader::generate(string path)
{
    ifstream file(path);
    string type, nb, w, h, s;

    if(file)
    {
        getline(file,type);
        getline(file, nb);
        getline(file, w);
        getline(file, h);
        getline(file, s);

        if(type=="unique")
        {
            return new SpriteUnique(int(stoi(nb)), int(stoi(w)), int(stoi(h)), s);
        }
        else if(type=="loop")
        {
            return new SpriteLoop(int(stoi(nb)), int(stoi(w)), int(stoi(h)), s);
        }
        else
        {
            cout<<"Erreur de type sprite : '"<< path << "'" << endl;
        }
        return nullptr;
    }

    else
    {
        cout << "ERREUR : sprite '" << path << "' non trouvé";
        return nullptr;
    }
}
