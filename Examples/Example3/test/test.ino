/* This is the generated code by the C++ program 
Program to run 3 patterns in a chronological order*/

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

a = new int[4] {0, 1, 2, 3, };
Pattern[1].initialize( THEATER_CHASE, FORWARD, 9001, 5, 0, 0, 0, 255, 9830400, 200, 500, a, 4);
delete [] a;

a = new int[4] {0, 1, 2 ,3,  };
Pattern[2].initialize( SCANNER, REVERSE, 13500, 5, 3, 0, 0, 255, 25700, 0, 500, a, 4);
}

void loop() {
for(int i = 0; i < 3; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
