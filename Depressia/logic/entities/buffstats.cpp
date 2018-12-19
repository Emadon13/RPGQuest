#include "buffstats.h"

BuffStats::BuffStats()
{
    for(unsigned i=0 ; i<nbStats ; i++)
        buffs[i] = OneBuffStat();
}

void BuffStats::buff(StatToBuff stat)
{
    buffs[stat].buff();
}

void BuffStats::debuff(StatToBuff stat)
{
    buffs[stat].debuff();
}

void BuffStats::toNormal()
{
    for(unsigned i=0 ; i<nbStats ; i++)
        buffs[i].toNormal();
}

void BuffStats::reset()
{
    for(unsigned i=0 ; i<nbStats ; i++)
        buffs[i].toNormal();
}

float BuffStats::getCoef(StatToBuff stat)
{
    return buffs[stat].getCoef();
}

int BuffStats::getTurnsLeft(StatToBuff stat)
{
    return buffs[stat].getTurnsLeft();
}

