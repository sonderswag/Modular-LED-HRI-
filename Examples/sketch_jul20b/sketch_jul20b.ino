#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(10, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[1];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 0, 0, 255, 16711680, 0, 1000, (int []){0, 1, 2, 3, }, 4);
}

void loop() {
for(int i = 0; i < 1; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
