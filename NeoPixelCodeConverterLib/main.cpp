/* Program to run multiple patterns simultaneously*/


#include <iostream>
#include <fstream>
#include <string>
#include <LightParameter.h>
#include <NeoPixelCodeConverter.h>
#include <vector>

using namespace std;




NeoPixelCodeConverter b;

vector<LightParameter> a;

int main()
{

    string filename;
    int no_of_leds = 14;
    int d1[] = {0,1,2,3};
    int d2[] = {5,6,7,8,9};
    int d3[] = {11,12,13};
    cout<<sizeof(d1)<<"\n";
                                                                                                                                                // a[1] = b.initialize(RAINBOW_CYCLE,FORWARD, 0, 3000, 0, 255, 255, 0, 3, d1,sizeof(d1)/4);

    //a.push_back(LightParameter(RAINBOW_CYCLE,FORWARD, 0, 3000, 0, 255, 255, 0, 3, d1,sizeof(d1)/4));
 // a.push_back(UpdateData(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int index, int Totalsteps, int Brightness, uint32_t color1, unsigned long interval, int g[], int length)

    cout<<"Enter the whole path and also name of the file\n";
    cin>>filename;

    uint32_t c = b.Color(150,0,0);
    uint32_t c1 = b.Color(0,0,200);
    cout<<c1<<"\n";
    //cout<<a[1].pattern<<"y\n";
    cout<<"af\n";
    //int d[] = {5,6,7,8,9};
    a.push_back(LightParameter(RAINBOW_CYCLE,FORWARD, 0, 3000, 0,0,0, 255,0,0, 3, d1,sizeof(d1)/4));
    //a.push_back(LightParameter(THEATER_CHASE,FORWARD, 9001, 10, 0,0,0, 255, c, c1, 500, d1,sizeof(d1)/4));

    a.push_back(LightParameter(SCANNER,REVERSE, 0, 5, 0,0,0, 255, b.Color(0, 100, 100), 0, 500, d2,sizeof(d2)/4));
   // a.push_back(LightParameter(BLINK,REVERSE, 21500, 5, 0,0,0, 255, b.Color(0, 100, 150), 0, 1000, d2,sizeof(d2)/4));

    a.push_back(LightParameter(ON_AND_OFF,REVERSE, 0, 5, 0, 1000,2500, 255, b.Color(50, 100, 150), 0, 1000, d3,sizeof(d3)/4));
   // a.push_back(LightParameter(LOADING,REVERSE, 21500, 2, 0, 1000,2500, 255, b.Color(250, 50, 150), 0, 500, d3,sizeof(d3)/4));
    //a[0] = b.initialize(THEATER_CHASE,FORWARD, 5000, 10, 0, 255, 255, c, c1, 500, d, sizeof(d)/4);

   // a.push_back(LightParameter(THEATER_CHASE,FORWARD, 5000, 10, 0, 255, 255, c, c1, 500, d, sizeof(d)/4));

    b.create(a,no_of_leds,a.size(),filename);

}
