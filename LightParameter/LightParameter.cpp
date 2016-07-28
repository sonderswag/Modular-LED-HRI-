#include "LightParameter.h"

/** \brief Initializes all the light parameters for a particular instance of the structure depending on user input
 *
 * \param Pattern This variable holds one of the supported patterns
 * \param dir Specifies the direction in which the pattern will run
 * \param start Specifies the start time of the parameter
 * \param Cycle Specifies the number of times the pattern is supposed to run
 * \param Index Specifies the Index from which the pattern is suppose to start from
 * \param on This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be on.
 * \param off This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be off.
 * \param Brightness Used to set the brightness of the LED's.
 * \param color1 Used to set the color of the pattern(used by majority of the patterns).
 * \param color2 Used to set the 2nd color of the pattern(in this library only THEATER_CHASE uses this parameter).
 * \param Interval Used to set the time for which 1 cycle will run
 * \param g[] Stores the ID's of group of LED's in a pattern.
 * \param gLength Specifies the number of LED's that are part of a pattern.
 * \return void
 *
 */

void LightParameter::initialize(ActivePattern Pattern, Direction dir, unsigned long start, int Cycle, int Index,
                                unsigned long on, unsigned long off, int Brightness, uint32_t color1, uint32_t color2,
                                unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    startTime = start;
    stopTime = 100;
    cycles = Cycle;
    index = Index;
    onTime = on;
    offTime = off;
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
    ledstate = false;
}

LightParameter::LightParameter(){
}

/** \brief a constructor
 *
 * The job of this constructor is similar to the initialize function
 */
LightParameter::LightParameter(ActivePattern Pattern, Direction dir, unsigned long start, int cycle, int Index,
                                unsigned long on, unsigned long off, int Brightness, uint32_t color1, uint32_t color2,
                                unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    startTime = start;
    cycles = cycle;
    index = Index;
    onTime = on;
    switch(Pattern)
        {
        case RAINBOW_CYCLE:
            onTime = 0;
            offTime = 0;
            direction = FORWARD;
            Color1 = 0;
            Color2 = 0;
            break;
        case THEATER_CHASE:
            onTime = 0;
            offTime = 0;
            direction = FORWARD;
            Color1 = color1;
            Color2 = color2;
            break;
        case COLOR_WIPE:
            onTime = 0;
            offTime = 0;
            direction = dir;
            Color1 = color1;
            Color2 = 0;
            break;
        case SCANNER:
            onTime = 0;
            offTime = 0;
            direction = dir;
            Color1 = color1;
            Color2 = 0;
            break;
         case FADE:
            onTime = 0;
            offTime = 0;
            direction = FORWARD;
            Color1 = color1;
            Color2 = 0;
            break;
            break;
         case BLINK:
            onTime = 0;
            offTime = 0;
            direction = FORWARD;
            Color1 = color1;
            Color2 = 0;
            break;
         case ON_AND_OFF:
            onTime = on;
            offTime = off;
            direction = FORWARD;
            Color1 = color1;
            Color2 = 0;
            break;
         case PULSATING:
            onTime = 0;
            offTime = 0;
            direction = FORWARD;
            Color1 = color1;
            Color2 = 0;
            break;
         case LOADING:
            onTime = 0;
            offTime = 0;
            direction = dir;
            Color1 = color1;
            Color2 = 0;
            break;
         case STEP:
            onTime = 0;
            offTime = 0;
            direction = dir;
            Color1 = color1;
            Color2 = 0;
            break;
         default:
            break;
        }
    brightness = Brightness;
    interval = Interval;
    for( int i = 0; i < length; i++)
    {
        group[i] = g[i];
    }
    grouplength = length;
    lastupdate = 0;
    complete = -1;
    ledstate = false;
}


/*LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index,
                                int Brightness, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    startTime = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
    complete = -1;
    interval = Interval;
    onTime = 0;
    offTime = 0;
    Color1 = 0;
    Color2 = 0;
    lastupdate = 0;
    grouplength = length;
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }
}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index,
                                int Brightness, uint32_t color1, unsigned long Interval, int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    startTime = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
    complete = -1;
    interval = Interval;
    onTime = 0;
    offTime = 0;
    Color1 = color1;
    Color2 = 0;
    lastupdate = 0;
    grouplength = length;
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }
}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index,
                                int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval,
                                int g[], int length)
{
    pattern = Pattern;
    direction = dir;
    startTime = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
    complete = -1;
    interval = Interval;
    onTime = 0;
    offTime = 0;
    Color1 = color1;
    Color2 = color2;
    lastupdate = 0;
    grouplength = length;
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }

}

LightParameter::LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int on,
                                int off, int Index, int Brightness, uint32_t color1, unsigned long Interval,
                                int g[], int length)
{
    pattern = Pattern;

    direction = dir;
    startTime = start;
    cycles = cycle;
    index = Index;
    brightness = Brightness;
    totalsteps = 0;
    complete = -1;
    interval = Interval;
    Color1 = color1;
    Color2 = 0;
    lastupdate = 0;
    onTime = on;
    offTime = off;
    grouplength = length;
    for( int i=0; i < grouplength; i++)
    {
        group[i] = g[i];
    }
}*/
