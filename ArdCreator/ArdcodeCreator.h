//  ArdcodeCreator.h - Creates code for arduino

#ifndef ARDCODECREATOR_h
#define ARDCODECREATOR_h

#include <iostream>
#include <fstream>
#include <Update_Data.h>

using namespace std;

class ArdcodeCreator{

public:
    void create(UpdateData a[], int no_Leds, int no_Patterns);
    UpdateData initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[], int length);
    UpdateData initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int index, int totalsteps, int brightness, uint32_t color1, unsigned long interval, int g[], int length);
    UpdateData initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int totalsteps, int brightness, uint32_t color1, uint32_t color2, unsigned long interval, int g[], int length);              //initialization function(overloaded)
    uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
    uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
};

#endif
