#include <Adafruit_NeoPixel.h>
#include <Signalling.h>

void setup() {
  // put your setup code here, to run once:

    Update_Data Pattern1;
    Pattern1.pattern = RAINBOW_CYCLE;
    Pattern1.direction = FORWARD;
    Pattern1.startTime = 0;
    Pattern1.cycles = 5;
    Pattern1.Index = 0;
    Pattern1.brightness = 255;
    Pattern1.status = false;
    Pattern1.complete = false;
    Pattern1.interval = 100;        //change every 100 ms
    Pattern1.lastUpdate = 0;
    Pattern1.group = [1,3,5,7];
    Pattern1.groupLength = 4;
    
    
    Update_Data Pattern2;
    Pattern2.pattern = COLOR_WIPE;
    Pattern2.direction = REVERSE;
    Pattern2.startTime = 3;
    Pattern2.on_time = 5;
    Pattern2.Index = 0;
    Pattern2.brightness = 255;
    Pattern2.status = false;
    Pattern2.complete = false;
    Pattern1.interval = 200;        //change every 100 ms
    Pattern1.lastUpdate = 0;
    
    Pattern2.group = [2,4,6,8,10];
    Pattern2.groupLength = 5;
    
    
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
