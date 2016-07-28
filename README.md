# Modular-LED-HRI-
============
Readme file for our LED Modular System

GUI interacts with an Arduino, which will control the RGBW LED Strip

#Installation
* Clone it from Github using the command

```
git clone git@github.com:sonderswag/Modular-LED-HRI-.git
```

* Or download the zip file by clicking on **Clone or Download** and then click on **Download ZIP**

#SETUP
##Arduino Library

####1. LightSignal

To install the library, first make sure that the arduino application is not running on your PC. Then copy the "LightSignal" folder from the directory in which you extracted the ZIP file into the **_libraires_** folder. Under Windows, it will most likely have the following path "My Documents\Arduino\libraries". For Mac users, it will most likely be in "Documents/Arduino/libraries". On Linux, it will be the "libraries" folder in your sketchbook. 

Your Arduino library folder should now look like this (on Windows):
```
  My Documents\Arduino\libraries\LightSignal\LightSignal.cpp
  
  My Documents\Arduino\libraries\LightSignal\LightSignal.h
  ....
```

or like this (on Mac and Linux):
```
  Documents/Arduino/libraries/LightSignal/LigthSignal.cpp
  
  Documents/Arduino/libraries/LightSiganl/LightSignal.h
  ```
  
###2. LightParameter
  
  The procedure is same as above except instead of copying the whole folder, copy just the .h and .cpp file and put them in a "LightParameter" folder and then follow the above procedure
  
##C++ Library

Copy the "NeoPixelCodeConverter" and "LightParameter" folder into any directory you desire and then indicate the path to .a and the .h file under the linker settings of your C++ IDE.

The path to the .a file will look something like this:
```
"Path of the directory to which you copied the library"\LightParameter\bin\Debug
```
For the header file(.h), the path will be:
```
"Path of the directory to which you copied the library"\LightParameter
```

#USAGE
##1. Arduino Library

Sample programs are provided in the examples/ directory.E.g Under SIMUL, test.ino will run 3 patterns simultaneously (Here RAINBOW, SCANNER and ON_AND_OFF patterns will run at the same time). Other sample codes demonstrate patterns other than these three patterns. Additionally few codes demonstrate chronological running and also a combination of chronological and simulatneous running of multiple patterns.

##2. C++ Library

Sample programs are provided in the Example/ directory.E.g SIMUL.cpp which uses the NeoPixelCodeConverter Library to create a arduino code to run multiple patterns simultaneously.  

Note: Remember to include the "NeoPixelCodeCoverter.a" and "LightParameter.a" files under the build options before executing any program that uses the "LightParameter" and "NeoPixelCodeConverter" Library. Failing to do so will make the compiler give you an "undefined reference" error.





