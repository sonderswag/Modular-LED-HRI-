/* Signaling.h - Library for Non-verbal signaliing by Robots */

#ifndef SIGNALING_h
#define SIGNALING_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
//#include <string>

// Pattern types supported:
enum  ActivePattern { NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE };
// Patern directions supported:
enum  Direction { FORWARD, REVERSE };

struct Update_Data{
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

uint16_t group[100];
int groupLength;        //length of the group
};

class Signaling : public Adafruit_NeoPixel{

public:
       Signaling(uint16_t pixels, uint8_t pin, uint8_t type);
//    ~Signaling();

       void Update(Update_Data *a);
       bool OnComplete(bool c);
       void Increment(Update_Data *p);
       uint32_t DimColor(uint32_t color);
       uint8_t Red(uint32_t color);
       uint8_t Green(uint32_t color);
       uint8_t Blue(uint32_t color);
       uint32_t Wheel(byte WheelPos);
       void ColorSet(Update_Data *p, uint32_t color);

       void RainbowCycleUpdate(Update_Data *b);
       void TheaterChaseUpdate(Update_Data *b);
       void ColorWipeUpdate(Update_Data *b);
       void ScannerUpdate(Update_Data *b);
       void FadeUpdate(Update_Data *b);
       // Core Functionality
  /*   void on_and_off();
       void blink();
       void pulsating();
       void brightness();

       // Group Behaviour
       void step();
       void rainbow();
       void loadingbar();
       void alternatingblink();
       void policeblink();*/

};
#endif
