#include <Adafruit_NeoPixel.h>
#include <Signalling.h>

Signalling Strip(60, 6, NEO_GRBW + NEO_KHZ800);   
Update_Data Pattern1;
Update_Data Pattern2;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
    Strip.begin();
    
    Pattern1.pattern = RAINBOW_CYCLE;
    Pattern1.direction = FORWARD;
    Pattern1.startTime = 0;
    Pattern1.cycles = 5;
    Pattern1.Index = 0;
    Pattern1.brightness = 255;
    Pattern1.status = false;
    Pattern1.complete = false;
    Pattern1.Interval = 100;        //change every 100 ms
    Pattern1.lastUpdate = 0;
    Pattern1.group[0] = 1;
    Pattern1.group[1] = 3;
    Pattern1.group[2] = 5;
    Pattern1.group[3] = 7;
    Pattern1.groupLength = 4;
    
    Pattern2.pattern = COLOR_WIPE;
    Pattern2.direction = REVERSE;
    Pattern2.startTime = 3;
    Pattern2.on_time = 5;
    Pattern2.Index = 0;
    Pattern2.brightness = 255;
    Pattern2.status = false;
    Pattern2.complete = false;
    Pattern2.Interval = 200;        //change every 200 ms
    Pattern2.lastUpdate = 0;
    Pattern2.Color1 = Strip.Color(255,255,0);
    Pattern2.group[0] = 2;
    Pattern2.group[1] = 4;
    Pattern2.group[2] = 6;
    Pattern2.group[3] = 8;
    Pattern2.group[4] = 10;
    Pattern2.groupLength = 5;
    

}

void loop() 
{
  // put your main code here, to run repeatedly:
  Strip.Update(&Pattern1);
  Strip.Update(&Pattern2);
  
}
