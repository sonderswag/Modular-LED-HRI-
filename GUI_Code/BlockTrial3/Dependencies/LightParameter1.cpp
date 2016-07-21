#include "LightParameter.h"

/* Name:  initialize(function), LightParamteter(constructor)
Purpose: Initializes all the light parameters for the a particular instance of the structure depending on user input
Inputs: 1) Pattern: This variable holds one of the supported patterns.
        2) dir: Specifies the direction in which the LED's will glow.
        3) start: Specifies the start time of the parameter.
        4) cycle: Specifies the number of times the pattern is supposed to run.
        5) Index: Specifies the Index from which the pattern is suppose to start from
        6) on: This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be on.
        7) off: This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be off.
        8) Totalsteps: This variable is used to keep track of the LED brightness and the current color in the RAINBOW_CYCLE pattern.
        9) Brightness: Used to set the brightness of the LED's.
        10) color1: Used to set the color of the pattern(used by majority of the patterns).
        11) color2: Used to set the 2nd color of the pattern(in this library only THEATER_CHASE uses this parameter).
        12) Interval:  Used to set the time for which 1 cycle will run
        13) g[]: Stores the ID's of group of LED's in a pattern.
        14) gLength: Specifies the number of LED's that are part of a pattern.

*/

void LightParameter::initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int on, int off, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int length)
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
    brightness = Brightness;
    Color1 = color1;
    Color2 = color2;
    interval = Interval;
    for( int i = 0; i < length; i++)
    {
        group[i] = g[i];
    }
    grouplength = length;
    lastupdate = 0;
    complete = -1;
    ledstate = true;
}

LightParameter::LightParameter(){
}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Brightness, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
    complete = -1;
    interval = Interval;
    Color1 = 0;
    Color2 = 0;
    lastupdate = 0;
    grouplength = length;
    //cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }
}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
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

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
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

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int Index, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;

    direction = dir;
    start_time = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
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
