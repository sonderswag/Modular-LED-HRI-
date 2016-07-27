/* Program to run multiple patterns in a chronological order*/


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

    cout<<"Enter the whole path and also name of the file\n";
    cin>>filename;

    uint32_t c = b.Color(150,0,0);
    uint32_t c1 = b.Color(0,0,200);

    a.push_back(LightParameter(RAINBOW_CYCLE,FORWARD, 0, 3000, 0,0,0, 255,0,0, 3, d1,sizeof(d1)/4));

    a.push_back(LightParameter(THEATER_CHASE,FORWARD, 9001, 5, 0,0,0, 255, c, c1, 500, d1,sizeof(d1)/4));

    a.push_back(LightParameter(SCANNER,REVERSE, 13500, 5, 0,0,0, 255, b.Color(0, 100, 100), 0, 500, d1,sizeof(d1)/4));

    b.create(a, no_of_leds, a.size(), filename);

}
