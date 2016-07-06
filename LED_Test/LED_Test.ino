#include <Adafruit_NeoPixel.h>
#include <Signaling.h>
#include <UpdateData.h>

Signaling Strip(16, 6, NEO_RGBW + NEO_KHZ800);   
Update_Data Pattern1;
Update_Data Pattern2;
Update_Data Pattern4;
Update_Data Pattern3;
Update_Data Pattern5;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
    Strip.begin();
    
   /* Pattern1.pattern = RAINBOW_CYCLE;
    Pattern1.direction = FORWARD;
    Pattern1.startTime = 0;
    Pattern1.cycles = 100;
    Pattern1.Index = 0;
    Pattern1.brightness = 255;
    //Pattern1.status = false;
    Pattern1.complete = false;
    Pattern1.Interval = 3;        //change every 100 ms
    Pattern1.lastUpdate = 0;
    Pattern1.totalsteps=255;
    Pattern1.group[0] = 0;
    Pattern1.group[1] = 1;
    Pattern1.group[2] = 2;
    Pattern1.group[3] = 6;
    Pattern1.groupLength = 4;
    
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
    Pattern2.totalsteps=5;
    Pattern2.Color1 = Strip.Color(255,255,0);
    Pattern2.Color2 = Strip.Color(0,0,50);
    Pattern2.group[0] = 5;
    Pattern2.group[1] = 6;
    Pattern2.group[2] = 7;
    Pattern2.group[3] = 8;
    Pattern2.group[4] = 9;
    Pattern2.groupLength = 5;
    
    Pattern3.pattern = SCANNER;
    Pattern3.direction = FORWARD;
    Pattern3.startTime = 3;
    Pattern3.on_time = 5;
    Pattern3.Index = 0;
    Pattern3.brightness = 255;
  //  Pattern2.status = false;
    Pattern3.complete = false;
    Pattern3.Interval = 500;        //change every 200 ms
    Pattern3.lastUpdate = 0;
    Pattern3.groupLength=5;
    Pattern3.Color1 = Strip.Color(255,0,0);
  //  Pattern3.Color2 = Strip.Color(0,0,50);
    Pattern3.group[0] = 11;
    Pattern3.group[1] = 12;
    Pattern3.group[2] = 13;
    Pattern3.group[3] = 14;
    Pattern3.group[4] = 15;
    Pattern3.totalsteps = (Pattern3.groupLength-1)*2;*/
    
    Pattern4.pattern = PULSATING;
    Pattern4.direction = FORWARD;
    Pattern4.startTime = 3;
    Pattern4.on_time = 5;
    Pattern4.Index = 0;
    Pattern4.brightness = 255;
  //  Pattern2.status = false;
    Pattern4.complete = false;
    Pattern4.Interval = 50;        //change every 200 ms
    Pattern4.lastUpdate = 0;
    Pattern4.groupLength=5;
    Pattern4.Color1 = Strip.Color(255,255,0);
    Pattern4.Color2 = Strip.Color(0,0,50);
    Pattern4.group[0] = 11;
    Pattern4.group[1] = 12;
    Pattern4.group[2] = 13;
    Pattern4.group[3] = 14;
    Pattern4.group[4] = 15;
    Pattern4.LedState = false;
    Pattern4.totalsteps = Pattern4.groupLength;
    
  /*  Pattern5.pattern = STEP;
    Pattern5.direction = FORWARD;
    Pattern5.startTime = 0;
    Pattern5.on_time = 1000;
    Pattern5.off_time = 3000;
    Pattern5.Index = 0;
    Pattern5.brightness = 255;
  //  Pattern2.status = false;
    Pattern5.complete = false;
    Pattern5.Interval = 2000;        //change every 200 ms
    Pattern5.lastUpdate = 0;
    Pattern5.groupLength=5;
    Pattern5.Color1 = Strip.Color(255,255,0);
    Pattern5.Color2 = Strip.Color(0,0,50);
    Pattern5.group[0] = 0;
    Pattern5.group[1] = 2;
    Pattern5.group[2] = 3;
    Pattern5.group[3] = 4;
    Pattern5.group[4] = 5;
    Pattern5.totalsteps = Pattern5.groupLength;*/
    

}

void loop() 
{
  // put your main code here, to run repeatedly:
// Strip.Update(&Pattern1);
 //Strip.Update(&Pattern2);
  //Strip.Update(&Pattern3);
  Strip.Update(&Pattern4);
  
}
