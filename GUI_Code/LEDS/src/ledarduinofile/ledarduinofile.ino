#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(21, 6, NEO_GRBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

int* a = new int[8] {0, 1, 2, 3, 4, 5, 6, 7, };
Pattern[0].initialize( BLINK, FORWARD, 0, 1000, 0, 0, 0, 255, 16711680, 0, 40, a, 8);
delete [] a;

a = new int[13] {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, };
Pattern[1].initialize( SCANNER, FORWARD, 0, 100, 0, 0, 0, 255, 4982271, 0, 50, a, 13);
delete [] a;

}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}