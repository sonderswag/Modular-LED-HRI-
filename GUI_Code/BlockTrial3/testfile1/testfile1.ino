#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(21, 6, NEO_RGBW + NEO_KHZ800);

LightParameter Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

int* a = new int[9] {0, 1, 2, 3, 4, 5, 6, 7, 8, };
Pattern[0].initialize( RAINBOW_CYCLE, NO_DIR, 0, 2000, 0, 0, 0, 255, 0, 0, 10, a, 9);
delete [] a;

a = new int[11] {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, };
Pattern[1].initialize( THEATER_CHASE, NO_DIR, 2000, 20, 0, 0, 0, 255, 3866426, 3851419269, 100, a, 11);
delete [] a;




}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
