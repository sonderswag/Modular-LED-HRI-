#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(16, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 0, 8, 0, 255, 0, 0, 20, (int []){0, 1, 2, 3, 4, 5, 6, }, 7);
Pattern[1].initialize( THEATER_CHASE, FORWARD, 2000, 400, 0, 0, 8, 0, 255, 16769803, 4607, 10, (int []){7, 8, 9, 10, 11, 12, 13, 14, 15, }, 9);
}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}