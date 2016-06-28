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
    
    Pattern1.group = [1,3,5,7];
    Pattern1.groupLength = 4;
    
    
    
    
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
