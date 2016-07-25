#include "NeoPixelCodeConverter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <Dependencies/LightParameter.h>

/* Name:  create
Purpose:
Inputs:

*/
 //function to create arduino code
void NeoPixelCodeConverter::create(vector<LightParameter> a, int no_Leds, int no_Patterns)
{
    ofstream ofile("/home/lwathieu/Documents/GitHub/Modular-LED-HRI-/GUI_Code/BlockTrial3/testfile/testfile.ino");
    ofile<<"#include <Adafruit_NeoPixel.h>\n#include <LightSignal.h>\n#include <LightParameter.h>\n\nLightSignal Strip(";
    ofile<<no_Leds<<", 6, NEO_GRBW + NEO_KHZ800);\n\nLightParameter Pattern[";
    ofile<<no_Patterns<<"];\n\nvoid setup() {\nSerial.begin(115200);\nStrip.begin();\n\n";
    ofile<<"int* ";

    for( int i = 0; i < no_Patterns; i++)
    {

        ofile<<"a = new int["<<a[i].grouplength<<"] {";
        for( int j = 0; j < a[i].grouplength; j++)
        {
            ofile<<a[i].group[j]<<", ";
        }
        ofile<<"};\n";

        ofile<<"Pattern["<<i<<"].initialize( ";

        switch(a[i].pattern)
        {
        case RAINBOW_CYCLE:
            ofile<<"RAINBOW_CYCLE";
            break;
        case THEATER_CHASE:
            ofile<<"THEATER_CHASE";
            break;
        case COLOR_WIPE:
            ofile<<"COLOR_WIPE";
            break;
        case SCANNER:
            ofile<<"SCANNER";
            break;
         case FADE:
            ofile<<"FADE";
            break;
         case BLINK:
            ofile<<"BLINK";
            break;
         case ON_AND_OFF:
            ofile<<"ON_AND_OFF";
            break;
         case PULSATING:
            ofile<<"PULSATING";
            break;
         case LOADING:
            ofile<<"LOADING";
            break;
         case STEP:
            ofile<<"STEP";
            break;
         default:
            ofile<<"NO_PAT";
            break;
        }
        switch(a[i].direction)
        {
        case 1:
            ofile<<", FORWARD";
            break;
        case 2:
            ofile<<", REVERSE";
            break;
        default:
           ofile<<", NO_DIR";
           break;
        }
        ofile<<", "<<a[i].startTime<<", ";
        ofile<<a[i].cycles<<", ";
        ofile<<a[i].index<<", ";
        ofile<<a[i].onTime<<", ";
        ofile<<a[i].offTime<<", ";
        ofile<<a[i].brightness<<", ";
        ofile<<a[i].Color1<<", ";
        ofile<<a[i].Color2<<", ";
        ofile<<a[i].interval<<", ";
        ofile<<"a, ";
        ofile<<a[i].grouplength<<");\n";
        ofile<<"delete [] a;\n\n";

        //ofile<<"Pattern["<<i<<"].stopTime = Pattern["<<i<<"].cycles*Pattern["<<i<<"].Interval;\n\n";
    }
    ofile<<"}\n\nvoid loop() {\nfor(int i = 0; i < "<<no_Patterns<<"; i++){\n    Strip.mainLoop(&Pattern[i]);\n }\n}";

    ofile.close();
}

uint32_t NeoPixelCodeConverter::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

uint32_t NeoPixelCodeConverter::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}










/*UpdateData NeoPixelCodeConverter::initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[],int length)              //initialization function(overloaded)
{
    UpdateData c;

    c.pattern = Pattern;
    cout<<c.pattern<<"y\n";
    c.direction = dir;
    c.startTime = start;
    c.cycles = cycle;
    c.Index = index;
    c.brightness = brightness;
    c.totalsteps = totalsteps;
    //c.status = false;
    c.complete = false;
    c.Interval = interval;
    c.Color1 = color1;
    c.Color2 = 0;
    c.lastUpdate = 0;
    c.groupLength = length;
    cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < c.groupLength; i++)
    {
        c.group[i] = g[i];
    }


    return c;
}

UpdateData NeoPixelCodeConverter::initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, uint32_t color2, unsigned long interval, int g[], int length)              //initialization function(overloaded)
{
    UpdateData c;

    c.pattern = Pattern;
    cout<<c.pattern;
    c.direction = dir;
    c.startTime = start;
    c.cycles = cycle;
    c.Index = index;
    c.brightness = brightness;
    c.totalsteps = totalsteps;
    //c.status = false;
    c.complete = false;
    c.Interval = interval;
    c.Color1 = color1;
    c.Color2 = color2;
    c.lastUpdate = 0;
    c.groupLength = length;
    cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < c.groupLength; i++)
    {
        c.group[i] = g[i];
    }


    return c;
}
UpdateData NeoPixelCodeConverter::initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[], int length)
{
    UpdateData c;

    c.pattern = Pattern;
    cout<<c.pattern;
    c.direction = dir;
    c.startTime = start;
    c.cycles = cycle;
    c.Index = index;
    c.brightness = brightness;
    c.totalsteps = totalsteps;
    //c.status = false;
    c.complete = false;
    c.Interval = interval;
    c.Color1 = color1;
    c.Color2 = 0;
    c.lastUpdate = 0;
    c.on_time = on;
    c.off_time = off;
    c.groupLength = length;
    cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < c.groupLength; i++)
    {
        c.group[i] = g[i];
    }


    return c;
}*/

