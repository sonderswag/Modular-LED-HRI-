#include <Adafruit_NeoPixel.h>
#include <Signaling.h>
#include <UpdateData.h>
#include <vector>

Signaling Strip(16, 6, NEO_RGBW + NEO_KHZ800);

UpdateData Pattern[2];

//vector<UpdateData> a;

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 0, 7274832, 255, 255, 0, 0, 3, (int []){0, 1, 2, 3, }, 4);
Pattern[1].initialize( THEATER_CHASE, FORWARD, 5000, 10, 0, 4670144, 2686508, 255, 255, 16776960, 50, 500, (int []){5, 6, 7, 8, 9, }, 5);
}

void loop() {
for(int i = 0; i < 2; i++){
    Strip.mainLoop(&Pattern[i]);
 }
}
