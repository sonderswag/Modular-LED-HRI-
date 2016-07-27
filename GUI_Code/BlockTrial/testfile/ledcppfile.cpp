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

int* arr = new int[9] {0, 1, 2, 3, 4, 5, 6, 7, 8, };
a.push_back(LightParameter(RAINBOW_CYCLE, FORWARD, 0, 700, 0, 0, 0, 255, b.Color(0,0,0), b.Color(0,0,0), 50, arr, 9));
delete [] arr;

arr = new int[7] {9, 10, 11, 12, 13, 14, 15, };
a.push_back(LightParameter(BLINK, FORWARD, 1000, 700, 0, 0, 0, 255, b.Color(0,178,255), b.Color(0,178,255), 50, arr, 7));
delete [] arr;

b.create(a, 16, 2);

}