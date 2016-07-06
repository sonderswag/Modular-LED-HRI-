#include <Adafruit_NeoPixel.h>
#include <Signaling.h>
#include <UpdateData.h>

Signaling Strip(10, 6, NEO_RGBW + NEO_KHZ800);

Update_Data Pattern[2];

void setup() {
Serial.begin(115200);
Strip.begin();

Pattern[0].pattern =SCANNER;
Pattern[0].direction =REVERSE;
Pattern[0].Interval =3;
Pattern[0].lastUpdate =0;
Pattern[0].totalsteps =255;
Pattern[0].Color1 =16711680;
Pattern[0].Color2 =0;
Pattern[0].group[0] =2;
Pattern[0].group[1] =3;
Pattern[0].group[2] =4;
Pattern[0].group[3] =5;
Pattern[0].groupLength =4;
Pattern[0].stopTime = Pattern[0].cycles*Pattern[0].Interval;

Pattern[1].pattern =RAINBOW_CYCLE;
Pattern[1].direction =REVERSE;
Pattern[1].Interval =3;
Pattern[1].lastUpdate =0;
Pattern[1].totalsteps =255;
Pattern[1].Color1 =16711680;
Pattern[1].Color2 =0;
Pattern[1].group[0] =5;
Pattern[1].group[1] =6;
Pattern[1].group[2] =7;
Pattern[1].group[3] =8;
Pattern[1].groupLength =4;
Pattern[1].stopTime = Pattern[1].cycles*Pattern[1].Interval;

}

void loop() {
for(int i = 0; i < 2; i++){
if( Pattern[i].startTime >= millis() && Pattern[i].complete == -1){
Pattern[i].complete = 1;
}
else if( Pattern[i].stopTime <= millis() && Pattern[i].complete == 1){
Pattern[i].complete = 0;
}
if( Pattern[i].complete == 1){
Strip.Update(&Pattern[i]);
}
}
}