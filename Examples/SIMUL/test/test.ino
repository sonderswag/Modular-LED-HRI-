/* This is the generated code by the C++ program 
Program to run 3 patterns simulataneously*/

#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(14, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[3];

void setup() {
Serial.begin(115200);
Strip.begin();

int* a = new int[4] {0, 1, 2, 3, };
Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 0, 0, 255, 0, 0, 3, a, 4);
delete [] a;

a = new int[5] {5, 6, 7, 8, 9, };
Pattern[1].initialize( SCANNER, REVERSE, 0, 5, 0, 0, 0, 255, 25700, 0, 500, a, 5);
delete [] a;

a = new int[3] {11, 12, 13, };
Pattern[2].initialize( ON_AND_OFF, FORWARD, 0, 5, 0, 1000, 2500, 255, 3302550, 0, 1000, a, 3);
delete [] a;
}

void loop() {
for(int i = 0; i < 3; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
