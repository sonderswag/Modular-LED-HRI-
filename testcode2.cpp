#include <iostream>
#include <fstream>
#include <string>
#include <Update_Data.h>
#include <ArdcodeCreator.h>

using namespace std;

/*struct Update_Data{
public:
string direction;
string pattern;
int startTime;
int cycles;             //no of times the pattern should run
int Index;
int on_time;
int off_time;
int totalsteps;        //no of iterations
int brightness;          //the current brightness of the LED's

uint32_t Color1, Color2;    //required colors for the pattern

unsigned long Interval;
unsigned long lastUpdate;       //time at which the pattern was last updated

bool status;            //whether or not the pattern is currently running or not
bool complete;         //whether or not the pattern is complete or not

uint16_t group[100];
int groupLength;        //length of the group
};
*/


Update_Data a;
ArdcodeCreator b;

int main()
{
    a.pattern = "RAINBOW_CYCLE";
    cout<<a.pattern;
    a.direction = "FORWARD";
    a.startTime = 0;
    a.cycles = 100;
    a.Index = 0;
    a.brightness = 255;
    //a.status = false;
    a.complete = false;
    a.Interval = 3;        //change every 100 ms
    a.lastUpdate = 0;
    a.totalsteps=255;
    a.group[0] = 0;
    a.group[1] = 1;
    a.group[2] = 2;
    a.group[3] = 3;
    a.groupLength = 4;

  //  b.create(a);
/*ofstream ofile("test.ino");
ofile<<"#include <Adafruit_NeoPixel.h>\n#include <Signaling.h>\n#include <UpdateData.h>\nSignaling Strip(16, 6, NEO_RGBW + NEO_KHZ800);\nUpdate_Data Pattern1;\nvoid setup() {\nSerial.begin(115200);\nStrip.begin();\n";
ofile<<"Pattern1.pattern ="<<a.pattern<<";\n";
ofile<<"Pattern1.direction ="<<a.direction<<";\n";
ofile<<"Pattern1.Interval ="<<a.Interval<<";\n";
ofile<<"Pattern1.lastUpdate ="<<a.lastUpdate<<";\n";
ofile<<"Pattern1.totalsteps ="<<a.totalsteps<<";\n";
ofile<<"Pattern1.group[0] ="<<a.group[0]<<";\n";
ofile<<"Pattern1.group[1] ="<<a.group[1]<<";\n";
ofile<<"Pattern1.group[2] ="<<a.group[2]<<";\n";
ofile<<"Pattern1.group[3] ="<<a.group[3]<<";\n";
ofile<<"Pattern1.groupLength ="<<a.groupLength<<";}\n";
ofile<<"void loop() {\nStrip.Update(&Pattern1);\n}";
ofile.close();*/

}
