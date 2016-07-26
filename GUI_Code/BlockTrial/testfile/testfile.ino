#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(16, 6, NEO_GRBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

int* a = new int[8] {0, 1, 2, 3, 4, 5, 6, 7, };
Pattern[0].initialize( BLINK, FORWARD, 0, 800, 0, 0, 0, 255, 16768100, 0, 50, a, 8);
delete [] a;

a = new int[8] {8, 9, 10, 11, 12, 13, 14, 15, };
Pattern[1].initialize( BLINK, FORWARD, 0, 800, 0, 0, 0, 255, 9731898, 0, 50, a, 8);
delete [] a;

}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}