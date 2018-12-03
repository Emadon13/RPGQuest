#include "attack.h"

using namespace std;

Attack::Attack():
    Skill(),
    coef(0)
{

}

Attack::Attack(string n,
               string t,
               int mp,
               vector<Category> cat,
               double c):
    Skill(n, t, mp, cat),
    coef(c)

{

}

Sheet Attack::call(Entity& user, Entity& target)
{
    int deg;

    if (target.getDef() <= 0)
    {
        deg = int(user.getAtt()*user.getLvl()*coef);
    }

    else
    {
        deg = int((user.getAtt()*user.getLvl()*coef) / (target.getDef()));
    }

    if (deg > target.getHp()) deg = target.getHp();

    target.takeDamage(deg);

    vector<string> s;
    s.push_back(target.getName());

    vector<int> in;
    in.push_back(deg);

    if(coef == 1.0)
        return Sheet(user.getName(),
                     name,
                     s,
                     false,
                     in,
                     0,
                     normal,
                     attack);
}
