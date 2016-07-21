#include <Adafruit_NeoPixel.h>
#include <LightSignal.h>
#include <LightParameter.h>

LightSignal Strip(16, 6, NEO_RGBW + NEO_KHZ800);   

LightParameter Pattern[3];

void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
    Strip.begin();
    
    /*Pattern[1].pattern = RAINBOW_CYCLE;
    Pattern[1].direction = FORWARD;
    Pattern[1].startTime = 0;
    Pattern[1].cycles = 3000;
    Pattern[1].Index = 0;
    Pattern[1].brightness = 255;
    //Pattern[1].status = false;
    Pattern[1].complete = -1;
    Pattern[1].Interval = 3;        //change every 100 ms
    Pattern[1].lastUpdate = 0;
    Pattern[1].totalsteps=255;
    Pattern[1].group[0] = 0;
    Pattern[1].group[1] = 1;
    Pattern[1].group[2] = 2;
    Pattern[1].group[3] = 3;
    Pattern[1].groupLength = 4;
    Pattern[1].stopTime = Pattern[1].cycles*Pattern[1].Interval;*/
    
    Pattern[1].initialize( RAINBOW_CYCLE, FORWARD, 0, 3000, 0, 0, 0, 255, 0, 0, 3, (int []){ 0,1, 2, 3, 4 }, 5);
    //initialize(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int on, int off, int tsteps, int bright, uint32_t color1, uint32_t color2, unsigned long interval, int g[], int groupLenght)
    
    /*Pattern[0].pattern = THEATER_CHASE;
    Pattern[0].direction = FORWARD;
    Pattern[0].startTime = 5000;
    Pattern[0].cycles = 10;
    Pattern[0].on_time = 5;
    Pattern[0].Index = 0;
    Pattern[0].brightness = 255;
  //  Pattern[2].status = false;
    Pattern[0].complete = -1;
    Pattern[0].Interval = 500;        //change every 200 ms
    Pattern[0].lastUpdate = 0;
    Pattern[0].totalsteps=5;
    Pattern[0].Color1 = Strip.Color(255,255,0);
    Pattern[0].Color2 = Strip.Color(0,0,50);
    Pattern[0].group[0] = 5;
    Pattern[0].group[1] = 6;
    Pattern[0].group[2] = 7;
    Pattern[0].group[3] = 8;
    Pattern[0].group[4] = 9;
    Pattern[0].groupLength = 5;
    Pattern[0].stopTime = Pattern[0].startTime + (Pattern[0].cycles)*(Pattern[0].Interval);*/
    
     Pattern[0].initialize( THEATER_CHASE, FORWARD, 5000, 10, 0, 0, 0, 255, Strip.Color(255,255,0), Strip.Color(0,0,50), 500, (int []){ 5,6,7,8,9}, 5);
     
    Pattern[2].pattern = BLINK;
    Pattern[2].direction = FORWARD;
    Pattern[2].startTime = 3000;
    Pattern[2].cycles = 3;
    Pattern[2].onTime = 0;
    Pattern[2].index = 0;
    Pattern[2].brightness = 255;
  //  Pattern2.status = false;
    Pattern[2].complete = -1;
    Pattern[2].interval = 500;        //change every 200 ms
    Pattern[2].lastupdate = 0;
    Pattern[2].grouplength=5;
    Pattern[2].Color1 = Strip.Color(0,200,20);
  //  Pattern[2].Color2 = Strip.Color(0,0,50);
    Pattern[2].group[0] = 11;
    Pattern[2].group[1] = 12;
    Pattern[2].group[2] = 13;
    Pattern[2].group[3] = 14;
    Pattern[2].group[4] = 15;
    Pattern[2].totalsteps = 0;
    
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
 for(int i = 0; i < 3; i++)
 {
   Strip.mainLoop(&Pattern[i]);
   /*if( Pattern[i].startTime <= millis() && Pattern[i].complete == -1)                //checks if the pattern is suppose to start or not
   {
     Pattern[i].complete = 1;
   }
   else if( Pattern[i].stopTime <= millis() && Pattern[i].complete == 1)              //checks if the pattern run time is over or not
   {
     Pattern[i].complete = 0;
     Strip.OnComplete(&Pattern[i]);
   }
   if( Pattern[i].complete == 1)                                                       //updates the pattern 
   {
     Strip.Update(&Pattern[i]);
   }*/
   
 }
 
   // Strip.Update(&Pattern[1]);
    
}
