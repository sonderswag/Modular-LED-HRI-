#include "UpdateData.h"

void UpdateData::initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int on, int off, int tsteps, int bright, uint32_t color1, uint32_t color2, unsigned long interval, int g[], int glength)
{
    pattern = Pattern;
    direction = dir;
    startTime = start;
    stopTime = 500;
    cycles = cycle;
    Index = index;
    on_time = on;
    off_time = off;
    totalsteps = 255;
    brightness = bright;
    Color1 = color1;
    Color2 = color2;
    Interval = interval;
    for( int i = 0; i < glength; i++)
    {
        group[i] = g[i];
    }
    groupLength = glength;
    lastUpdate = 0;
    complete = -1;
    LedState = true;
}

void Add::add(int a,int b){

int c=a+b;
}
