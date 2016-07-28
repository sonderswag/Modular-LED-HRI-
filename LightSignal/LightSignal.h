/* Signaling.h - Library for Non-verbal signaling by Robots */

#ifndef LIGHTSIGNAL_h
#define LIGHTSIGNAL_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <LightParameter.h>

/** \class LightSignal
 * \brief Consists of different types of patterns that can be used to signal/convey a particular action.
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
       uint32_t Brightness(uint32_t color1, uint32_t internsity);
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
/*

       // Group Behaviour
       void alternatingblink();
       void policeblink();*/

};
#endif
