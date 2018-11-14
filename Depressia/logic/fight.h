#ifndef FIGHT_H
#define FIGHT_H

#include"logic/entities/entity.h"

using namespace std;

class Fight
{
public:
    Fight();
    Fight(vector<Entity> h, vector<Entity> o);




private:
    //static const int ne;
    vector <Entity> heroes;
    vector <Entity> opponents;

    void setOrder(Entity fighters[]);

};

#endif // FIGHT_H
