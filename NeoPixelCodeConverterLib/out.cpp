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

int* arr = new int[12] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, };
a.push_back(LightParameter(RAINBOW_CYCLE, FORWARD, 10, 2000, 0, 0, 0, 255, b.Color(0,0,0), b.Color(0,0,0), 10, arr, 12));
delete [] arr;

b.create(a, 12, 1, "/home/anurag/code/campus/Modular-LED-HRI/NeoPixelCodeConverterLib/out/out.ino");

}