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

int* arr = new int[1] {0, };
a.push_back(LightParameter(RAINBOW_CYCLE, FORWARD, 100, 0, 0, 0, 0, 255, b.Color(0,0,0), b.Color(0,0,0), 200, arr, 1));
delete [] arr;

b.create(a, 1, 1);

}