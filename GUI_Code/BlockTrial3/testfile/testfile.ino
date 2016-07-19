
#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(4, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[1];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( THEATER_CHASE, FORWARD, 0, 0, 0, 0, 8, 0, 255, 16742520, 2162687, 0, (int []){1, 2, 3, }, 3);
}

void loop() {
for(int i = 0; i < 1; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
