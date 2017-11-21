#include <fstream>
#include <string>
#include <string>
#include <LightParameter.h>
#include <NeoPixelCodeConverter.h>
#include <vector>

using namespace std;

int main()
{
  NeoPixelCodeConverter neoPixel;
  vector<LightParameter> leds;
  int ledIds[] = {0, 1, 2};
  leds.push_back(LightParameter(RAINBOW_CYCLE, //Pattern
                                FORWARD, // Pattern direction
                                10, 
                                2000, 
                                0, 0, 0, 255, 
                                neoPixel.Color(0,0,0), neoPixel.Color(0,0,0), 
                                10, ledIds, sizeof(ledIds)/sizeof(ledIds[0])));
   neoPixel.create(leds, sizeof(ledIds)/sizeof(ledIds[0]), 1, "out.ino");
}
