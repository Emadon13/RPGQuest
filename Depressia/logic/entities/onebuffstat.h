#ifndef ONEBUFFSTAT_H
#define ONEBUFFSTAT_H

#include <cstdlib>

class OneBuffStat
{
public:
    OneBuffStat();
    void buff();
    void debuff();
    void toNormal();
    void reset();

    float getCoef();
    int getTurnsLeft();

    static const unsigned maxBuff = 3;

private:
    unsigned value;
    unsigned turnsLeft;
    void incrTurnsLeft();
};

#endif // ONEBUFFSTAT_H
