#include <iostream>
#include <fstream>
#include <string>
#include <Update_Data.h>
#include <ArdcodeCreator.h>

using namespace std;



Update_Data a[2];
ArdcodeCreator b;

int main()
{
    /*a[1].pattern = "RAINBOW_CYCLE";
    cout<<a[1].pattern;
    a[1].direction = "FORWARD";
    a[1].startTime = 0;
    a[1].cycles = 100;
    a[1].Index = 0;
    a[1].brightness = 255;
    //a[1].status = false;
    a[1].complete = false;
    a[1].Interval = 3;        //change every 100 ms
    a[1].lastUpdate = 0;
    a[1].totalsteps=255;
    a[1].group[0] = 0;
    a[1].group[1] = 1;
    a[1].group[2] = 2;
    a[1].group[3] = 3;
    a[1].groupLength = 4;*/
   // cout<<"I see you\n";
    uint32_t c1 = b.Color(255,0,0,0);
    cout<<c1<<"\n";
    int d1[] = {5,6,7,8};
    cout<<sizeof(d1)<<"\n";
    a[1] = b.initialize("RAINBOW_CYCLE", "REVERSE", 0, 100, 1000, 2000, 0, 255, 100, c1, 3, d1);
    uint32_t c = b.Color(255,0,0,0);
    cout<<c;
    int d[] = {2,3,4,5};
    a[0] = b.initialize("SCANNER", "REVERSE", 0, 100, 0, 255, 100, c, 3, d);

    b.create(a,10,2);

}
