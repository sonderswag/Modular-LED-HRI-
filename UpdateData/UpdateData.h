#ifndef UPDATEDATA_h
#define UPDATEDATA_h

#include <Arduino.h>


//using namespace std;

// Pattern types supported:
enum  ActivePattern { NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE, BLINK, ON_AND_OFF, PULSATING, LOADING, STEP};
// Patern directions supported:
enum  Direction { FORWARD, REVERSE };

struct UpdateData{
ActivePattern pattern;
Direction direction;

unsigned long startTime;
unsigned long stopTime;
unsigned long cycles;             //no of times the pattern should run
int Index;
int on_time;
int off_time;
int totalsteps;        //no of iterations
int brightness;          //the current brightness of the LED's

uint32_t Color1, Color2;    //required colors for the pattern

unsigned long Interval;
unsigned long lastUpdate;       //time at which the pattern was last updated

//bool status;            //whether or not the pattern is currently running or not
char complete;         //whether or not the pattern is complete or not
bool LedState;

int group[100];
int groupLength;        //length of the group

void initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int on, int off, int tsteps, int bright, uint32_t color1, uint32_t color2, unsigned long interval, int g[], int glength);
};

class Add{
public:
    void add(int a,int b);
};
#endif // UPDATE_DATA_h

