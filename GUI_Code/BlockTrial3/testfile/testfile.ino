#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(0, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[0];

void setup() {
Serial.begin(115200);
Strip.begin();

int* }

void loop() {
for(int i = 0; i < 0; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}