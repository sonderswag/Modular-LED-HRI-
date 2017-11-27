# Modular-Lights
---
Modular-Lights is a framework to control LED strips via Arduino. LED strips can be used to display various light patterns.

This includes:
 - Universal IDE to program the Arduino using LED sketch board.
 - Arduino LED Library, It exposes the C++ APIs to be used in other programs. You can initialize the library and generate the *.ino files on runtime.
 

![example of the lights](https://github.com/sonderswag/Modular-LED-HRI-/blob/master/Photos/20160908_171027.jpg) 
![example of hexlights](https://github.com/sonderswag/Modular-LED-HRI-/blob/master/Photos/hexlight1.PNG)
---

## Requirements
 - cmake (>=3.4) to compile the C++ library.
 - QTCreator for IDE.
 - Arduino (>=1.8.0)

---

## Installation

To download the very latest source off the Git server do this:

    https://github.com/interaction-lab/Modular-Lights.git

(you'll get a directory named Modular Lights created, filled with the source code)

---

## Modular Lights IDE
![IDE](/GUI.png "IDE")

IDE is developed using the Qt framework. /GUI_CODE folder contains the code used for the IDE.
Sketch board makes it easier for the user to develop complex LED structures and a single-click upload button can be used to upload the pattern to the Arduino.


More information regarding the usage and code structure of the IDE can be found here[https://github.com/interaction-lab/Modular-Lights/blob/master/GUI_Code/BlockTrial/README.md]

---

## NeoPixelCodeConverter Library

NeoPixel Code Converter Library is a generic library that generates ino files based on the input configuration. These generated ino files utilizes the Arduino system calls to execute the desired Light Pattern behaviours. NeoPixel Code Converter Library hides away the complexity of maintaining LED states and also wraps the logic of updating LEDs with correct delay and color combinations.

Code for the library is under the folder /NeoPixelCodeConverterLib.

Example use of the library to generate the out.ino file in a particular location. 

    #include <fstream>
    #include <string>
    #include <string>
    #include <LightParameter.h>
    #include <NeoPixelCodeConverter.h>
    #include <vector>

    using namespace std;

    int main()
    {
      NeoPixelCodeConverter neoPixel;
      vector<LightParameter> leds;
      int ledIds[] = {0, 1, 2};
      leds.push_back(LightParameter(RAINBOW_CYCLE, //Pattern
                                    FORWARD, // Pattern direction
                                    10, 
                                    2000, 
                                    0, 0, 0, 255, 
                                    neoPixel.Color(0,0,0), neoPixel.Color(0,0,0), 
                                    10, ledIds, sizeof(ledIds)/sizeof(ledIds[0])));
       neoPixel.create(leds, sizeof(ledIds)/sizeof(ledIds[0]), 1, "out.ino");
    }
- source-code: /NeopixelCodeexample/example folder. The above code is from the example.cpp file.

The library is initialized using a vector of LightParameter objects. Each LightParameter object represents a group of LEDs along with their assigned Light Pattern behaviour. Currently supported Light Patterns are defined by the ActivePattern enum in LightParameter.h header.

APIs documentation can be found in the following header files:
 - NeoPixelCodeConverter/NeoPixelCodeConverter.h
 - LightParameter/LightParameter.h

####Compilation

    $/NeoPixelCodeConverterLib/example$ cmake CMakeLists.txt 
    -- Configuring done
    -- Generating done
    -- Build files have been written to: XXXX/NeoPixelCodeConverterLib/example
    $/NeoPixelCodeConverterLib/example$ make
    [ 33%] Built target LightParameter
    [ 66%] Built target NeoPixelCodeConverter
    Scanning dependencies of target neopixelexample
    [ 83%] Building CXX object CMakeFiles/neopixelexample.dir/example.cpp.o
    [100%] Linking CXX executable neopixelexample
    [100%] Built target neopixelexample
    $/NeoPixelCodeConverterLib/example$ ./neopixelexample 
    $/NeoPixelCodeConverterLib/example$ less out.ino

####Output
This should generate the following out.ino file in the example folder

    #include <Adafruit_NeoPixel.h>
    #include <LightSignal.h>
    #include <LightParameter.h>

    LightSignal Strip(3, 6, NEO_GRBW + NEO_KHZ800);

    LightParameter Pattern[1];

    void setup() {
    Serial.begin(115200);
    Strip.begin();

    int* a = new int[3] {0, 1, 2, };
    Pattern[0].initialize( RAINBOW_CYCLE, FORWARD, 10, 2000, 0, 0, 0, 255, 0, 0, 10, a, 3);
    delete [] a;

    }

    void loop() {
    for(int i = 0; i < 1; i++){
        Strip.mainLoop(&Pattern[i]);
     }
    }

---
#### Upload to Arduino

    $> arduino --upload out.ino --port `$1/find_usbport.sh | grep "Arduino" | awk '{print $1}'`
    
 Above command tries its best to get port of the connected Arduino. You can also provide the port number directly, for  example:
 
      $> arduino --upload out.ino --port /dev/ttyACM0
      
You can also upload the *.ino sketch from the C++ code by using system() function.

    system("arduino --upload out.ino --port /dev/ttyACM0");
    

---

###License Information

MIT License

Copyright (c) [2017]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---





