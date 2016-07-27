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

    cout<<"Enter the whole path and also name of the file\n";
    cin>>filename;

    a.push_back(LightParameter(RAINBOW_CYCLE,FORWARD, 0, 3000, 0,0,0, 255,0,0, 3, d1,sizeof(d1)/4));

    a.push_back(LightParameter(SCANNER,REVERSE, 0, 5, 0,0,0, 255, b.Color(0, 100, 100), 0, 500, d2,sizeof(d2)/4));

    a.push_back(LightParameter(ON_AND_OFF,REVERSE, 0, 5, 0, 1000,2500, 255, b.Color(50, 100, 150), 0, 1000, d3,sizeof(d3)/4));

    b.create(a, no_of_leds, a.size(), filename);

}
