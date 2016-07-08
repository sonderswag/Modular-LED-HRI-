/* Signaling.h - Library for Non-verbal signaliing by Robots */

#ifndef SIGNALING_h
#define SIGNALING_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <UpdateData.h>
#include <string>

/*// Pattern types supported:
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
*/
class Signaling : public Adafruit_NeoPixel{

public:
       Signaling(uint16_t pixels, uint8_t pin, uint8_t type);
//    ~Signaling();


       void Update(UpdateData *a);
       void OnComplete(UpdateData *a);
       void Increment(UpdateData *p);
       uint32_t DimColor(uint32_t color);
       uint8_t Red(uint32_t color);
       uint8_t Green(uint32_t color);
       uint8_t Blue(uint32_t color);
       uint32_t Wheel(byte WheelPos);
       void ColorSet(UpdateData *p, uint32_t color);
       uint32_t Brightness(uint32_t color1, uint32_t color2, uint32_t internsity);
       void mainLoop(UpdateData *a);

       void RainbowCycleUpdate(UpdateData *b);
       void TheaterChaseUpdate(UpdateData *b);
       void ColorWipeUpdate(UpdateData *b);
       void ScannerUpdate(UpdateData *b);
       void FadeUpdate(UpdateData *b);
       void BlinkUpdate(UpdateData *b);
       void OnOffUpdate(UpdateData *b);
       void PulsatingUpdate(UpdateData *b);
       void LoadingUpdate(UpdateData *b);
       void StepUpdate(UpdateData *b);
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
