#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(16, 6, NEO_GRBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

int* a = new int[9] {0, 1, 2, 3, 4, 5, 6, 7, 8, };
Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 700, 0, 0, 0, 255, 0, 0, 50, a, 9);
delete [] a;

a = new int[7] {9, 10, 11, 12, 13, 14, 15, };
Pattern[1].initialize( BLINK, FORWARD, 1000, 700, 0, 0, 0, 255, 45823, 0, 50, a, 7);
delete [] a;

}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}