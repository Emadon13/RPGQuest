#include "onebuffstat.h"
#include <iostream>

using namespace std;
OneBuffStat::OneBuffStat():
    value(maxBuff),
    turnsLeft(0)
{

}

void OneBuffStat::buff()
{
    if(value < 2*maxBuff)
        value++;

    incrTurnsLeft();
}

void OneBuffStat::debuff()
{
    if(value > 0)
        value--;

    incrTurnsLeft();
}

void OneBuffStat::toNormal()
{
    if(turnsLeft > 0)
        turnsLeft--;
    if(turnsLeft == 0)
        value = maxBuff;
}

void OneBuffStat::reset()
{
    value = maxBuff;
}

float OneBuffStat::getCoef()
{
    return float(float(value)/float(maxBuff));

}

int OneBuffStat::getTurnsLeft()
{
    return int(turnsLeft);
}

void OneBuffStat::incrTurnsLeft()
{
    turnsLeft += unsigned(maxBuff-unsigned(abs(int(value)-int(maxBuff))));
}
