#ifndef UPDATE_DATA_h
#define UPDATE_DATA_h

//#include <Arduino.h>
#include <iostream>

enum  ActivePattern { NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE, BLINK, ON_AND_OFF, PULSATING, LOADING, STEP};
// Patern directions supported:
enum  Direction { FORWARD, REVERSE };


using namespace std;

struct UpdateData{
ActivePattern pattern;
Direction direction;

int startTime;
int cycles;             //no of times the pattern should run
int Index;
int on_time;
int off_time;
int totalsteps;        //no of iterations
int brightness;          //the current brightness of the LED's

uint32_t Color1, Color2;    //required colors for the pattern

unsigned long Interval;
unsigned long lastUpdate;       //time at which the pattern was last updated

bool status;            //whether or not the pattern is currently running or not
bool complete;         //whether or not the pattern is complete or not

int group[100];
int groupLength;        //length of the group

UpdateData *next;

//UpdateData();
//UpdateData(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[]);
//UpdateData(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, uint32_t color2, unsigned long interval, int g[]);
//UpdateData(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[]);
};

#endif // UPDATE_DATA_h

