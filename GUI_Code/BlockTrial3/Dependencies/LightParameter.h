#ifndef LIGHTPARAMETER_h
#define LIGHTPARAMETER_h

#include <iostream>
//#include <Arduino.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


//using namespace std;

// Pattern types supported:
enum  ActivePattern { NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE, BLINK, ON_AND_OFF, PULSATING, LOADING, STEP};
// Patern directions supported:
enum  Direction { FORWARD, REVERSE };

struct LightParameter{
ActivePattern pattern;
Direction direction;

unsigned long start_time;
unsigned long stop_time;
unsigned long cycles;             //no of times the pattern should run
int index;
int on_time;
int off_time;
int totalsteps;        //no of iterations
int brightness;          //the current brightness of the LED's

uint32_t Color1, Color2;    //required colors for the pattern

unsigned long interval;
unsigned long lastupdate;       //time at which the pattern was last updated

//bool status;            //whether or not the pattern is currently running or not
char complete;         //whether or not the pattern is complete or not
bool ledstate;

int group[100];
int grouplength;        //length of the group

//UpdateData();

LightParameter();
LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Totalsteps, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length);
LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Totalsteps, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int length);
LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int Index, int Totalsteps, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length);

void initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int on, int off, int tsteps, int bright, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int glength);
};


#endif // LightParameter_h

