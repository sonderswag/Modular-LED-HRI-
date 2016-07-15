/* Signaling.h - Library for Non-verbal signaling by Robots */

#ifndef LIGHTSIGNAL_h
#define LIGHTSIGNAL_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <LightParameter.h>
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
class LightSignal : public Adafruit_NeoPixel{

public:
       LightSignal(uint16_t pixels, uint8_t pin, uint8_t type);

       void Update(LightParameter *a);
       void OnComplete(LightParameter *a);
       void Increment(LightParameter *p);
       uint32_t DimColor(uint32_t color);
       uint8_t Red(uint32_t color);
       uint8_t Green(uint32_t color);
       uint8_t Blue(uint32_t color);
       uint32_t Wheel(byte WheelPos);
       void ColorSet(LightParameter *p, uint32_t color);
       uint32_t Brightness(uint32_t color1, uint32_t color2, uint32_t internsity);
       void mainLoop(LightParameter *a);

       void RainbowCycleUpdate(LightParameter *b);
       void TheaterChaseUpdate(LightParameter *b);
       void ColorWipeUpdate(LightParameter *b);
       void ScannerUpdate(LightParameter *b);
       void FadeUpdate(LightParameter *b);
       void BlinkUpdate(LightParameter *b);
       void OnOffUpdate(LightParameter *b);
       void PulsatingUpdate(LightParameter *b);
       void LoadingUpdate(LightParameter *b);
       void StepUpdate(LightParameter *b);
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
