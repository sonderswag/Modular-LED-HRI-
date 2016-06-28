/* Signalling.h - Library for Non-verbal signaliing by Robots */

#ifndef Signalling_h
#define Signalling_h

#include "Ardunio.h"
#include "Adafruit_NeoPixel.h"

struct Update_Data{
string pattern;
string direction;

int startTime;
int cycles;             //no of times the pattern should run
int Index;
int on_time;
int off_time;
int totalsteps;        //no of iterations
int brightness;          //the current brightness of the LED's

uint32_t Color1, Color2;    //required colors for the pattern

unsigned long interval;
unsigned long lastUpdate;       //time at which the pattern was last updated

bool status;            //whether or not the pattern is currently running or not
bool complete;         //whether or not the pattern is complete or not

int *group;
int groupLength;        //length of the group
};

class Signalling : public Adafruit_NeoPixel{

public:
       Signalling();

       void RainbowCycleUpdate(Update_Data *b);
       void TheaterChaseUpdate(Update_Data *b);
       void ColorWipeUpdate(Update_Data *b);
       void ScannerUpdate(Update_Data *b);
       void FadeUpdate(Update_Data *b);
       // Core Functionality
       void on_and_off();
       void blink();
       void pulsating();
       void brightness();

       // Group Behaviour
       void step();
       void rainbow();
       void loadingbar();
       void alternatingblink();
       void policeblink();

}
