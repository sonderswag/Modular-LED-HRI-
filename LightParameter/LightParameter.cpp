#include "LightParameter.h"

void LightParameter::initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int on, int off, int tsteps, int bright, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int glength)
{
    pattern = Pattern;
    direction = dir;
    start_time = start;
    stop_time = 500;
    cycles = cycle;
    index = Index;
    on_time = on;
    off_time = off;
    totalsteps = 255;
    brightness = bright;
    Color1 = color1;
    Color2 = color2;
    interval = Interval;
    for( int i = 0; i < glength; i++)
    {
        group[i] = g[i];
    }
    grouplength = glength;
    lastupdate = 0;
    complete = -1;
    ledstate = true;
}

LightParameter::LightParameter(){
}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Totalsteps, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    //cout<<pattern;
    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = Totalsteps;
    //status = false;
    complete = -1;
    interval = Interval;
    Color1 = color1;
    Color2 = 0;
    lastupdate = 0;
    grouplength = length;
    //cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }
}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Totalsteps, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    //cout<<pattern;
    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = Totalsteps;
    //status = false;
    complete = -1;
    interval = Interval;
    Color1 = color1;
    Color2 = color2;
    lastupdate = 0;
    grouplength = length;
   // cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }

}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int Index, int Totalsteps, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
   // cout<<pattern;
    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = Totalsteps;
    //status = false;
    complete = -1;
    interval = Interval;
    Color1 = color1;
    Color2 = 0;
    lastupdate = 0;
    on_time = on;
    off_time = off;
    grouplength = length;
    //cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }
}
