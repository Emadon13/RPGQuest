#include "dialogloader.h"

using namespace std;

DialogLoader::DialogLoader()
{

}

Dialog DialogLoader::generate()
{
    Dialog dialog;
    return dialog;
}

Dialog DialogLoader::generate(string path)
{
    ifstream file(path);
    string line, d, n, t, i;
    Direction dir;

    if(file)
    {
        getline(file, line);
        vector<DialogElement> dialog(0);

        while(line != "end")
        {
            d = line;
            if (d == "left")
                dir = direction_left;

            else if (d == "right")
                dir = direction_right;

            else
            {
                cout << "ERREUR : type de direction invalide " << d << endl;
                dir = direction_left;
            }

            getline(file,n);
            getline(file,t);
            getline(file, i);

            DialogElement de(dir, n, t, i);
            dialog.push_back(de);
            getline(file,line);
        }

        return Dialog(dialog);
    }

    else
    {
        return generate();
    }
}
