#include "spriteloader.h"

using namespace std;

SpriteLoader::SpriteLoader()
{

}

Sprite* SpriteLoader::generate()
{
    return nullptr;
}

Sprite* SpriteLoader::generate(string path)
{
    ifstream file(path);
    vector<string> sprite;
    string s, nn, nw, nh, ns, dn, dw, dh, ds, an, aw, ah, as, sn, sw, sh, ss, kn, kw, kh, ks;

    if(file)
    {

        getline(file, nn);
        getline(file, nw);
        getline(file, nh);
        getline(file, ns);
        getline(file, dn);
        getline(file, dw);
        getline(file, dh);
        getline(file, ds);
        getline(file, an);
        getline(file, aw);
        getline(file, ah);
        getline(file, as);
        getline(file, sn);
        getline(file, sw);
        getline(file, sh);
        getline(file, ss);
        getline(file, kn);
        getline(file, kw);
        getline(file, kh);
        getline(file, ks);

        return new Sprite(int(stoi(nn)), int(stoi(nw)), int(stoi(nh)), ns,
                          int(stoi(dn)), int(stoi(dw)), int(stoi(dh)), ds,
                          int(stoi(an)), int(stoi(aw)), int(stoi(ah)), as,
                          int(stoi(sn)), int(stoi(sw)), int(stoi(sh)), ss,
                          int(stoi(kn)), int(stoi(kw)), int(stoi(kh)), ks);

    }

    else
    {
        cout << "ERREUR : sprite " << path << "non trouvé";
        return nullptr;
    }


}
/*
Sprite makeSprite(vector<string> spriteElements)
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
}
*/
