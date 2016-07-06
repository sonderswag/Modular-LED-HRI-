#include <Adafruit_NeoPixel.h>
#include <Signaling.h>
#include <UpdateData.h>

Signaling Strip(16, 6, NEO_RGBW + NEO_KHZ800);   

Update_Data Pattern[2];

void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
    Strip.begin();
    
    Pattern[1].pattern = RAINBOW_CYCLE;
    Pattern[1].direction = FORWARD;
    Pattern[1].startTime = 0;
    Pattern[1].cycles = 100;
    Pattern[1].Index = 0;
    Pattern[1].brightness = 255;
    //Pattern[1].status = false;
    Pattern[1].complete = false;
    Pattern[1].Interval = 3;        //change every 100 ms
    Pattern[1].lastUpdate = 0;
    Pattern[1].totalsteps=255;
    Pattern[1].group[0] = 0;
    Pattern[1].group[1] = 1;
    Pattern[1].group[2] = 2;
    Pattern[1].group[3] = 3;
    Pattern[1].groupLength = 4;
    Pattern[1].stopTime = Pattern[1].cycles*Pattern[1].Interval;
    
    Pattern[2].pattern = THEATER_CHASE;
    Pattern[2].direction = FORWARD;
    Pattern[2].startTime = 3;
    Pattern[1].cycles = 100;
    Pattern[2].on_time = 5;
    Pattern[2].Index = 0;
    Pattern[2].brightness = 255;
  //  Pattern[2].status = false;
    Pattern[2].complete = false;
    Pattern[2].Interval = 500;        //change every 200 ms
    Pattern[2].lastUpdate = 0;
    Pattern[2].totalsteps=5;
    Pattern[2].Color1 = Strip.Color(255,255,0);
    Pattern[2].Color2 = Strip.Color(0,0,50);
    Pattern[2].group[0] = 5;
    Pattern[2].group[1] = 6;
    Pattern[2].group[2] = 7;
    Pattern[2].group[3] = 8;
    Pattern[2].group[4] = 9;
    Pattern[2].groupLength = 5;
    Pattern[2].stopTime = Pattern[2].cycles*Pattern[2].Interval;
    
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
 for(int i = 0; i < 2; i++)
 {
   if( Pattern[i].startTime >= millis() && Pattern[i].complete == -1)                //checks if the pattern is suppose to start or not
   {
     Pattern[i].complete = 1;
   }
   else if( Pattern[i].stopTime <= millis() && Pattern[i].complete == 1)              //checks if the pattern run time is over or not
   {
     Pattern[i].complete = 0;
   }
   if( Pattern[i].complete == 1)                                                       //updates the pattern 
   {
     Strip.Update(&Pattern[i]);
   }
   
 }
 
    
    
}
