#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(10, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 0, 0, 255, 0, 0, 3, (int []){0, 1, 2, 3, }, 4);
Pattern[1].initialize( STEP, FORWARD, 1000, 3000, 0, 1000, 2000, 255, 16776960, 0, 1000, (int []){5, 6, 7, 8, 9}, 5);

}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
