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


    int d1[] = {0,1,2,3};
    cout<<sizeof(d1)<<"\n";
                                                                                                                                                // a[1] = b.initialize(RAINBOW_CYCLE,FORWARD, 0, 3000, 0, 255, 255, 0, 3, d1,sizeof(d1)/4);

    //a.push_back(LightParameter(RAINBOW_CYCLE,FORWARD, 0, 3000, 0, 255, 255, 0, 3, d1,sizeof(d1)/4));
 // a.push_back(UpdateData(ActivePattern Pattern, Direction dir, int start, int cycle, int on, int off, int index, int Totalsteps, int Brightness, uint32_t color1, unsigned long interval, int g[], int length)

    uint32_t c = b.Color(255,0,0,0);
    uint32_t c1 = b.Color(0,0,50,0);
    cout<<c1<<"\n";
    //cout<<a[1].pattern<<"y\n";
    cout<<"af\n";
    //int d[] = {5,6,7,8,9};
    a.push_back(LightParameter(PULSATING,FORWARD, 0, 300, 0, 255, c, 3, d1,sizeof(d1)/4));
    //a[0] = b.initialize(THEATER_CHASE,FORWARD, 5000, 10, 0, 255, 255, c, c1, 500, d, sizeof(d)/4);

   // a.push_back(LightParameter(THEATER_CHASE,FORWARD, 5000, 10, 0, 255, 255, c, c1, 500, d, sizeof(d)/4));

    b.create(a,10,1);

}
