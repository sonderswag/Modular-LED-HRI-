#include <Adafruit_NeoPixel.h>
#include <Signalling.h>

Signalling Strip(10, 6, NEO_RGBW + NEO_KHZ800);   
Update_Data Pattern1;
Update_Data Pattern2;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
    Strip.begin();
    
  /*  Pattern1.pattern = RAINBOW_CYCLE;
    Pattern1.direction = FORWARD;
    Pattern1.startTime = 0;
    Pattern1.cycles = 100;
    Pattern1.Index = 0;
    Pattern1.brightness = 255;
    //Pattern1.status = false;
    Pattern1.complete = false;
    Pattern1.Interval = 3;        //change every 100 ms
    Pattern1.lastUpdate = 0;
    Pattern1.totalsteps=4;
    Pattern1.group[0] = 0;
    Pattern1.group[1] = 2;
    Pattern1.group[2] = 4;
    Pattern1.group[3] = 6;
    Pattern1.groupLength = 255;*/
    
   Pattern2.pattern = THEATER_CHASE;
    Pattern2.direction = FORWARD;
    Pattern2.startTime = 3;
    Pattern2.on_time = 5;
    Pattern2.Index = 0;
    Pattern2.brightness = 255;
  //  Pattern2.status = false;
    Pattern2.complete = false;
    Pattern2.Interval = 500;        //change every 200 ms
    Pattern2.lastUpdate = 0;
    Pattern2.totalsteps=0;
    Pattern2.Color1 = Strip.Color(255,255,0);
    Pattern2.Color2 = Strip.Color(0,0,50);
    Pattern2.group[0] = 1;
    Pattern2.group[1] = 2;
    Pattern2.group[2] = 3;
    Pattern2.group[3] = 4;
    Pattern2.group[4] = 5;
    Pattern2.groupLength = 5;
    

}

void loop() 
{
  // put your main code here, to run repeatedly:
  //Strip.Update(&Pattern1);
  Strip.Update(&Pattern2);
  
}
