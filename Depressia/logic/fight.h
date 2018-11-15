#ifndef FIGHT_H
#define FIGHT_H

#include<array>
#include"logic/entities/entity.h"


class Fight
{
public:
    Fight();
    Fight(std::vector<Entity>, std::vector<Entity> o);

    std::vector<Entity> getHeroes();
    std::vector<Entity> getOppenents();
    std::vector<Entity> getAll_e();




private:

    static const int nb_e = 2;
    Entity heroes[nb_e];
    std::vector<Entity> opponents;
    std::vector<Entity> all_e;


    void setOrder(std::vector <Entity> fighters);
};

#endif // FIGHT_H
