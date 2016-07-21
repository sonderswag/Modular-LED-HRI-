#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(21, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[4];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 1, 3, 0, 0, 8, 0, 255, 0, 0, 2, (int []){0, 1, 2, 3, 4, }, 5);
Pattern[1].initialize( THEATER_CHASE, FORWARD, 1, 3, 0, 0, 8, 0, 255, 16734254, 392191, 2, (int []){5, 6, 7, 8, }, 4);
Pattern[2].initialize(    ON_AND_OFF, REVERSE, 1, 3, 0, 21, 22, 0, 255, 1703680, 0, 2, (int []){9, 10, 11, }, 3);
Pattern[3].initialize(         BLINK, FORWARD, 1, 3, 0, 0, 8, 0, 255, 8959, 0, 2, (int []){12, 13, 14, 15, 16, 17, 18, 19, 20, }, 9);
}

void loop() {
for(int i = 0; i < 4; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
