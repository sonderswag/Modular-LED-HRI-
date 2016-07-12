#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(10, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 6357328, 6363288, 255, 255, 0, 0, 3, (int []){0, 1, 2, 3, }, 4);
Pattern[1].initialize( THEATER_CHASE, FORWARD, 5000, 10, 0, 2686508, 2686440, 255, 255, 16776960, 50, 500, (int []){5, 6, 7, 8, 9, }, 5);
}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}