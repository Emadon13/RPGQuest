#include "dialogloader.h"

using namespace std;

DialogLoader::DialogLoader()
{

}

vector <Dialog> DialogLoader::generate()
{
    Dialog d;
    vector<Dialog> dialogs(0);
    dialogs.push_back(d);
    return dialogs;
}

vector<Dialog> DialogLoader::generate(string path)
{

    ifstream file(path);
    string line, d, n, t, i;
    Direction dir;

    if(file)
    {
        vector<Dialog> dialogs(0);

        getline(file, line);
        while(line != "end")
        {

            vector<DialogElement> dialogElements(0);

            while(line != "end_dial")
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
                dialogElements.push_back(de);
                getline(file,line);
            }

            Dialog dialog(dialogElements);
            dialogs.push_back(dialog);
            getline(file,line);
        }

        return dialogs;
    }

    else
    {
        return generate();
    }
}
