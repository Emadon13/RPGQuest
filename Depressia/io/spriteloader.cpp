#include "spriteloader.h"

using namespace std;

SpriteLoader::SpriteLoader()
{

}

vector<string> SpriteLoader::generate()
{
    return vector<string>(20,"0");
}

vector<string> SpriteLoader::generate(string path)
{
    ifstream file(path);
    vector<string> sprite;
    string s;

    if(file)
    {
        for(int i=0 ; i<5 ; i++)
        {
            getline(file, s);
            sprite.push_back(s);
        }

        return sprite;
    }

    else
    {
        cout << "ERREUR : sprite " << path << "non trouvé";
        return vector<string>(20,"0");
    }


}

/*Sprite makeSprite(vector<string> spriteElements)
{
    string nn, nw, nh, ns, dn, dw, dh, ds, an, aw, ah, as, sn, sw, sh, ss, kn, kw, kh, ks;
    nn = spriteElements.at(0);
    nw = spriteElements.at(1);
    nh = spriteElements.at(2);
    ns = spriteElements.at(3);
    dn = spriteElements.at(4);
    dw = spriteElements.at(5);
    dh = spriteElements.at(6);
    ds = spriteElements.at(7);
    an = spriteElements.at(8);
    aw = spriteElements.at(9);
    ah = spriteElements.at(10);
    as = spriteElements.at(11);
    sn = spriteElements.at(12);
    sw = spriteElements.at(13);
    sh = spriteElements.at(14);
    ss = spriteElements.at(15);
    kn = spriteElements.at(16);
    kw = spriteElements.at(17);
    kh = spriteElements.at(18);
    ks = spriteElements.at(19);

    return Sprite(nn, nw, nh, ns, dn, dw, dh, ds, an, aw, ah, as, sn, sw, sh, ss, kn, kw, kh, ks);
}*/
