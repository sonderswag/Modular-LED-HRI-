#include "ArdcodeCreator.h"
#include <iostream>
#include <fstream>
#include <Update_Data.h>


void ArdcodeCreator::create(Update_Data a[], int no_Leds, int no_Patterns)                      //function to create arduino code
{
    ofstream ofile("test.ino");
    ofile<<"#include <Adafruit_NeoPixel.h>\n#include <Signaling.h>\n#include <UpdateData.h>\n\nSignaling Strip("<<no_Leds<<", 6, NEO_RGBW + NEO_KHZ800);\n\nUpdate_Data Pattern["<<no_Patterns<<"];\n\nvoid setup() {\nSerial.begin(115200);\nStrip.begin();\n\n";
    for( int i = 0; i < no_Patterns; i++)
    {
        ofile<<"Pattern["<<i<<"].pattern ="<<a[i].pattern<<";\n";
        ofile<<"Pattern["<<i<<"].direction ="<<a[i].direction<<";\n";
        ofile<<"Pattern["<<i<<"].Interval ="<<a[i].Interval<<";\n";
        ofile<<"Pattern["<<i<<"].lastUpdate ="<<a[i].lastUpdate<<";\n";
        ofile<<"Pattern["<<i<<"].totalsteps ="<<a[i].totalsteps<<";\n";
        ofile<<"Pattern["<<i<<"].Color1 ="<<a[i].Color1<<";\n";
        ofile<<"Pattern["<<i<<"].Color2 ="<<a[i].Color2<<";\n";
        for( int j = 0; j < a[i].groupLength; j++)
        {
            ofile<<"Pattern["<<i<<"].group["<<j<<"] ="<<a[i].group[j]<<";\n";
        }
        ofile<<"Pattern["<<i<<"].groupLength ="<<a[i].groupLength<<";\n";
        ofile<<"Pattern["<<i<<"].stopTime = Pattern["<<i<<"].cycles*Pattern["<<i<<"].Interval;\n\n";
    }
    ofile<<"}\n\nvoid loop() {\nfor(int i = 0; i < "<<no_Patterns<<"; i++){\nif( Pattern[i].startTime >= millis() && Pattern[i].complete == -1){\nPattern[i].complete = 1;\n}\n";
    ofile<<"else if( Pattern[i].stopTime <= millis() && Pattern[i].complete == 1){\nPattern[i].complete = 0;\n}\nif( Pattern[i].complete == 1){\nStrip.Update(&Pattern[i]);\n}\n}\n}";
    ofile.close();
}

Update_Data ArdcodeCreator::initialize(string Pattern, string dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[])              //initialization function(overloaded)
{
    Update_Data c;

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
    c.groupLength = sizeof(g);
    cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < c.groupLength; i++)
    {
        c.group[i] = g[i];
    }


    return c;
}

Update_Data ArdcodeCreator::initialize(string Pattern, string dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, uint32_t color2, unsigned long interval, int g[])              //initialization function(overloaded)
{
    Update_Data c;

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
    c.groupLength = sizeof(g);
    cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < c.groupLength; i++)
    {
        c.group[i] = g[i];
    }


    return c;
}
Update_Data ArdcodeCreator::initialize(string Pattern, string dir, int start, int cycle, int on, int off, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[])
{
    Update_Data c;

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
    c.groupLength = sizeof(g);
    cout<<sizeof(g)<<"\n"<<g[3]<<"\n";
    for( int i=0; i < c.groupLength; i++)
    {
        c.group[i] = g[i];
    }


    return c;
}

uint32_t ArdcodeCreator::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

uint32_t ArdcodeCreator::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}
