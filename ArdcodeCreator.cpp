#include "ArdcodeCreator.h"
#include <iostream>
#include <fstream>
#include <Update_Data.h>


void ArdcodeCreator::create(Update_Data a)
{
    ofstream ofile("test.ino");
    ofile<<"#include <Adafruit_NeoPixel.h>\n#include <Signaling.h>\n#include <UpdateData.h>\nSignaling Strip(16, 6, NEO_RGBW + NEO_KHZ800);\nUpdate_Data Pattern1;\nvoid setup() {\nSerial.begin(115200);\nStrip.begin();\n";
    ofile<<"Pattern1.pattern ="<<a.pattern<<";\n";
    ofile<<"Pattern1.direction ="<<a.direction<<";\n";
    ofile<<"Pattern1.Interval ="<<a.Interval<<";\n";
    ofile<<"Pattern1.lastUpdate ="<<a.lastUpdate<<";\n";
    ofile<<"Pattern1.totalsteps ="<<a.totalsteps<<";\n";
    ofile<<"Pattern1.group[0] ="<<a.group[0]<<";\n";
    ofile<<"Pattern1.group[1] ="<<a.group[1]<<";\n";
    ofile<<"Pattern1.group[2] ="<<a.group[2]<<";\n";
    ofile<<"Pattern1.group[3] ="<<a.group[3]<<";\n";
    ofile<<"Pattern1.groupLength ="<<a.groupLength<<";}\n";
    ofile<<"void loop() {\nStrip.Update(&Pattern1);\n}";
    ofile.close();
}

