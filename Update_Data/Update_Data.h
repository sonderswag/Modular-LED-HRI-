#ifndef UPDATE_DATA_h
#define UPDATE_DATA_h

//#include <Arduino.h>
#include <iostream>

using namespace std;

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

unsigned long Interval;
unsigned long lastUpdate;       //time at which the pattern was last updated

bool status;            //whether or not the pattern is currently running or not
bool complete;         //whether or not the pattern is complete or not

uint16_t group[100];
int groupLength;        //length of the group
};

#endif // UPDATE_DATA_h

