#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(2, 6, NEO_GRBW + NEO_KHZ800);

LightParameter Pattern[1];

void setup() {
Serial.begin(115200);
Strip.begin();

int* a = new int[2] {0, 1, };
Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 10, 2000, 0, 0, 0, 255, 0, 0, 1, a, 2);
delete [] a;

}

void loop() {
for(int i = 0; i < 1; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}