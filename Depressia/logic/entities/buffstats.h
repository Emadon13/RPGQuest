#ifndef BUFFSTATS_H
#define BUFFSTATS_H

#include"logic/entities/onebuffstat.h"

enum StatToBuff {buffAttack, buffDefense, buffSpeed};
class BuffStats
{
public:
    BuffStats();
    void buff(StatToBuff stat);
    void debuff(StatToBuff stat);
    void toNormal();
    void reset();

    float getCoef(StatToBuff stat);
    int getTurnsLeft(StatToBuff stat);

    static const unsigned nbStats = 3;

private:
    OneBuffStat buffs[nbStats];
};

#endif // BUFFSTATS_H
