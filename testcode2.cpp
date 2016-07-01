#include <iostream>
#include <fstream>
#include <string>
#include <Update_Data.h>
#include <ArdcodeCreator.h>

using namespace std;



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

    b.create(a);

}
