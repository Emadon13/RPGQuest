#include "spriteloader.h"

using namespace std;

SpriteLoader::SpriteLoader()
{

}

Sprite SpriteLoader::generate()
{
    return Sprite(0, 0, 0, "",
                  0, 0, 0, "",
                  0, 0, 0, "",
                  0, 0, 0, "",
                  0, 0, 0, "");
}

Sprite SpriteLoader::generate(string path)
{
    ifstream file(path);
    string nn, nw, nh, ns, dn, dw, dh, ds, an, aw, ah, as, sn, sw, sh, ss, kn, kw, kh, ks;

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

        return Sprite(int(stoi(nn)), int(stoi(nw)), int(stoi(nh)), ns,
                      int(stoi(dn)), int(stoi(dw)), int(stoi(dh)), ds,
                      int(stoi(an)), int(stoi(aw)), int(stoi(ah)), as,
                      int(stoi(sn)), int(stoi(sw)), int(stoi(sh)), ss,
                      int(stoi(kn)), int(stoi(kw)), int(stoi(kh)), ks);
    }

    else
    {
        cout << "ERREUR : sprite " << path << "non trouvé";
        return Sprite(0, 0, 0, "",
                      0, 0, 0, "",
                      0, 0, 0, "",
                      0, 0, 0, "",
                      0, 0, 0, "");
    }


}
