#include "NeoPixelCodeConverter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

 /** \brief Function to create arduino code
  *
  * The create() function creates a ".ino" file, to which it writes the relevant code to run all the patterns on the LED's using the arduino
  * \param a List of all the patterns
  * \param no_Leds Total no. of modules/LED's being used
  * \param no_Patterns  Total no. of patterns
  * \param file Specifies the path and name of the file (after the file name please include .ino)
  * \return void
  *
  */
 void NeoPixelCodeConverter::create(vector<LightParameter> a, int no_Leds, int no_Patterns, string file)
{
    ofstream ofile(file.c_str());
    ofile<<"#include <Adafruit_NeoPixel.h>\n#include <LightSignal.h>\n#include <LightParameter.h>\n\nLightSignal Strip(";
    ofile<<no_Leds<<", 6, NEO_GRBW + NEO_KHZ800);\n\nLightParameter Pattern[";
    ofile<<no_Patterns<<"];\n\nvoid setup() {\nSerial.begin(115200);\nStrip.begin();\n\n";
    ofile<<"int* ";

    for( int i = 0; i < no_Patterns; i++)
    {
        ofile<<"a = new int["<<a[i].grouplength<<"] {";
        for( int j = 0; j < a[i].grouplength; j++)
        {
            ofile<<a[i].group[j]<<", ";
        }
        ofile<<"};\n";

        ofile<<"Pattern["<<i<<"].initialize( ";


        switch(a[i].pattern)
        {
        case RAINBOW_CYCLE:
            ofile<<"RAINBOW_CYCLE";
            break;
        case THEATER_CHASE:
            ofile<<"THEATER_CHASE";
            break;
        case COLOR_WIPE:
            ofile<<"COLOR_WIPE";
            break;
        case SCANNER:
            ofile<<"SCANNER";
            break;
         case FADE:
            ofile<<"FADE";
            break;
         case BLINK:
            ofile<<"BLINK";
            break;
         case ON_AND_OFF:
            ofile<<"ON_AND_OFF";
            break;
         case PULSATING:
            ofile<<"PULSATING";
            break;
         case LOADING:
            ofile<<"LOADING";
            break;
         case STEP:
            ofile<<"STEP";
            break;
         default:
            ofile<<"NONE";
            break;
        }
        switch(a[i].direction)
        {
        case FORWARD:
            ofile<<", FORWARD";
            break;
        case REVERSE:
            ofile<<", REVERSE";
            break;
        }
        ofile<<", "<<a[i].startTime<<", ";
        ofile<<a[i].cycles<<", ";
        ofile<<a[i].index<<", ";
        ofile<<a[i].onTime<<", ";
        ofile<<a[i].offTime<<", ";
        ofile<<a[i].brightness<<", ";
        ofile<<a[i].Color1<<", ";
        ofile<<a[i].Color2<<", ";
        ofile<<a[i].interval<<", ";
        ofile<<"a, ";
        ofile<<a[i].grouplength<<");\n";
        ofile<<"delete [] a;\n\n";
    }
    ofile<<"}\n\nvoid loop() {\nfor(int i = 0; i < "<<no_Patterns<<"; i++){\n    Strip.mainLoop(&Pattern[i]);\n }\n}";

    ofile.close();
}

/** \brief Converts RGB values to a 32 bit unsigned integer
 *
 * \param r Value of the Red color (b/w 0-255)
 * \param g Value of the Green color (b/w 0-255)
 * \param b Value of the Blue color (b/w 0-255)
 * \return uint32_t
 *
 */

uint32_t NeoPixelCodeConverter::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

/** \brief Converts RGBW values to a 32 bit unsigned integer
 *
 * \param r Value of the Red color (b/w 0-255)
 * \param g Value of the Green color (b/w 0-255)
 * \param b Value of the Blue color (b/w 0-255)
 * \param w Value of the White color (b/w 0-255)
 * \return uint32_t
 *
 */
uint32_t NeoPixelCodeConverter::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}



