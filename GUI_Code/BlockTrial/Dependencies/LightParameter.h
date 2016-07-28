#ifndef LIGHTPARAMETER_h
#define LIGHTPARAMETER_h


//#include <Arduino.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


//using namespace std;

// Pattern types supported:
enum  ActivePattern { NO_PAT,
                      RAINBOW_CYCLE,
                      THEATER_CHASE,
                      COLOR_WIPE,
                      SCANNER,
                      FADE,
                      BLINK,
                      ON_AND_OFF,
                      PULSATING,
                      LOADING,
                      STEP};

// Patern directions supported:
enum  Direction { FORWARD,
                  REVERSE };


/* Name:  LightParameter( struct)
Purpose: Responsible for holding values that define a particular pattern
Inputs: 1) pattern: This variable holds one of the supported patterns.
        2) direction: Specifies the direction in which the LED's will glow.
        3) startTime: Specifies the start time of the pattern.
        5) stopTime: Specifies the stop time of the pattern( the calculation of stop time varies from pattern to pattern)
        5) cycle: Specifies the number of times the pattern is supposed to run.
        6) index: Specifies the Index from which the pattern is suppose to start from
        6) onTime: This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be on.
        7) offTime: This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be off.
        8) totalsteps: This variable is used to keep track of the LED brightness and the current color in the RAINBOW_CYCLE pattern.
        9) brightness: Used to set the brightness of the LED's.
        10) Color1: Used to set the color of the pattern(used by majority of the patterns).
        11) Color2: Used to set the 2nd color of the pattern(in this library only THEATER_CHASE uses this parameter).
        12) interval:  Used to set the time for which 1 cycle will run
        13) lastupdate: Specifies the time at which the pattern was last updated.
        14) complete: Specifies whether or not the pattern is completed.
        15)
        16) group[100]: Stores the ID's of group of LED's in a pattern.
        17) grouplength: Specifies the number of LED's that are part of a pattern.

*/

struct LightParameter{
ActivePattern pattern;
Direction direction;

unsigned long startTime;
unsigned long stopTime;
unsigned long cycles;             //no of times the pattern should run

int index;
unsigned long onTime;
unsigned long offTime;
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



LightParameter();

LightParameter(ActivePattern Pattern, Direction dir, unsigned long start, int cycle, int Index,
                                unsigned long on, unsigned long off, int Brightness, uint32_t color1, uint32_t color2,
                                unsigned long Interval, int g[], int length);
/*LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Brightness, unsigned long Interval, int g[], int length);
LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length);
LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int Index, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval, int g[], int length);
LightParameter(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int Index, int Brightness, uint32_t color1, unsigned long Interval, int g[], int length);*/

void initialize(ActivePattern Pattern, Direction dir, unsigned long start, int cycle, int Index,
                unsigned long on, unsigned long off, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval,
                int g[], int length);
};


#endif // LightParameter_h

