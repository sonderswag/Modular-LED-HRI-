#include "displaywindow.h"
#include "ui_displaywindow.h"
#include <mainwindow.h>
#include <ledlabel.h>
#include "Dependencies/LightParameter.h"
#include "Dependencies/NeoPixelCodeConverter.h"
#include <QtAlgorithms>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <vector>

//pointer will store MainWindow that calls this DisplayWindow
MainWindow *parentForDWin;
//pointer to vector of LightParameters (patterns), initialized with mainwindow's
//*vectOfData
std::vector<LightParameter> *vecOfStructures;
//declare NeoPixelCodeConverter object that will translate patterns to
//Arduino code
NeoPixelCodeConverter codeConverter;


/*
 * A Window which displays each Group along with its many attributes.
 * Uses ClickableDisplay object to display clickable text.
 * Once the groups are satisfactory, can push button to upload to Arduino
 * or generate c++ code which uses the library.
 *
 */

DisplayWindow::DisplayWindow(std::vector<LightParameter> *vecofStruct,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayWindow)
{
    //initialize and set up
    ui->setupUi(this);
    vecOfStructures = vecofStruct;
    this->setWindowTitle("View and Edit Groups");
    parentForDWin = (MainWindow*)(this->parentWidget());
}

DisplayWindow::~DisplayWindow()
{
    qDebug() << "DisplayWindow destructor";
    delete ui;
}

//Clears the displayInfo (a ClickableDisplay object), and write info to it.
//Writes info in black, clickable text in red (EDIT, DELETE), and displays
//pattern color as well
void DisplayWindow::DisplayInfo()
{
    //clear past writing
    ui->displayInfo->clear();
    //loop through vector of patterns
    for (int m = 0; m < vecOfStructures->size(); m++)
    {
        //display group name in black
        PrintNewLn(QString("Group %1 ").arg(m));
        //change font to bold red, This is formattable text
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        format.setForeground(QBrush(QColor(200,0,0)));
        PrintSameLn(format, QString("(EDIT)"));
        PrintSameLn(format, QString("  "));
        PrintSameLn(format, QString("(DELETE)"));
        //change font to black normal
        format.setFontWeight(QFont::Normal);
        format.setForeground(QBrush(Qt::black));
        PrintSameLn(format, QString(" :"));
        //Builds a Qstring to display all LED IDs in the pattern
        QString group = "LEDs: #";
        QString sep = ", #";
        for(int n = 0; n < vecOfStructures->at(m).grouplength; n++)
        {
            QString id = QString::number(vecOfStructures->at(m).group[n]);
            group = QString(group + id + sep);
        }
        group.chop(3);

        //print all information about the pattern
        PrintNewLnTab(group);
        PrintNewLnTab(QString("Grouplength: %1")
                 .arg(vecOfStructures->at(m).grouplength));
        PrintNewLnTab(QString("Pattern: " +
                         getPattern(vecOfStructures->at(m).pattern)));
        PrintNewLnTab(QString("Direction: " +
                         getDirection(vecOfStructures->at(m).direction)));
        PrintNewLnTab(QString("Start Time: %1")
                 .arg(vecOfStructures->at(m).startTime));
        PrintNewLnTab(QString("Interval: %1")
                 .arg(vecOfStructures->at(m).interval));
        PrintNewLnTab(QString("Cycles: %1")
                 .arg(vecOfStructures->at(m).cycles));
        PrintNewLnTab(QString("Calculated Stop Time: %1 Seconds")
                 .arg((parentForDWin->getStopTime(vecOfStructures->at(m)))
                      /1000.0));
        //only print color 1 if pattern needs it (all but Rainbow)
        if (vecOfStructures->at(m).pattern != RAINBOW_CYCLE)
        {
        uint32_t c1 = vecOfStructures->at(m).Color1;
        PrintNewLnTab(QString("Color 1 RGB: (%1, %2,  %3) -> ")
                 .arg(parentForDWin->Red(c1)).arg(parentForDWin->Green(c1))
                      .arg(parentForDWin->Blue(c1)));
        //Set font to bold and color 1
        format.setFontWeight(QFont::Bold);
        format.setForeground(QBrush(QColor(parentForDWin->Red(c1),
                                           parentForDWin->Green(c1),
                                           parentForDWin->Blue(c1))));
        //write some text in color 1, to give user idea of color
        PrintSameLn(format, QString("THIS COLOR"));
        //change font back to black
        format.setFontWeight(QFont::Normal);
        format.setForeground(QBrush(Qt::black));
        PrintSameLn(format, QString(" "));
        }
        //only print color 2 if color 2 has been been changed from 0 (default)
        if (vecOfStructures->at(m).Color2 != 0)
        {
            uint32_t c2 = vecOfStructures->at(m).Color2;
            PrintNewLnTab(QString("Color 2 RGB: (%1, %2,  %3) -> ")
                     .arg(parentForDWin->Red(c2)).arg(parentForDWin->Green(c2))
                          .arg(parentForDWin->Blue(c2)));
            //Set font to bold and color 2
            format.setFontWeight(QFont::Bold);
            format.setForeground(QBrush(QColor(parentForDWin->Red(c2),
                                               parentForDWin->Green(c2),
                                               parentForDWin->Blue(c2))));
            //write some text in color 2, to give user idea of color
            PrintSameLn(format, QString("THIS COLOR"));
            //change font back to black
            format.setFontWeight(QFont::Normal);
            format.setForeground(QBrush(Qt::black));
            PrintSameLn(format, QString(" "));
        }
        //adds newline
        PrintNewLn(QString(""));
    }
}


//prints "printthis" to same line in font "format"
void DisplayWindow::PrintSameLn(QTextCharFormat format, QString printthis)
{
    //cursor is set to the text's cursor, prints with format
    QTextCursor cursor(ui->displayInfo->textCursor());
    cursor.setCharFormat(format);
    cursor.insertText(printthis);
    ui->displayInfo->moveCursor(QTextCursor::End);
}

//prints "printthis" to new line
void DisplayWindow::PrintNewLn(QString printthis)
{
    ui->displayInfo->append(printthis);
}

//prints "printthis" with a tab in front to a new line
void DisplayWindow::PrintNewLnTab(QString printthis)
{
    QString tab = "      ";
    ui->displayInfo->append(QString(tab + printthis));
}

//get string of Direction name if given direction index
QString DisplayWindow::getDirection(int dirID)
{
    switch (dirID)
    {
        case FORWARD:
            return "FORWARD";
            break;
        case REVERSE:
            return "REVERSE";
            break;
    }
}

//get string of pattern name if given pattern index
QString DisplayWindow::getPattern(int patternID)
{
    switch (patternID)
    {
        case NO_PAT:
            return "NONE";
            break;
        case RAINBOW_CYCLE:
            return "RAINBOW_CYCLE";
            break;
        case THEATER_CHASE:
            return "THEATER_CHASE";
            break;
        case COLOR_WIPE:
            return "COLOR_WIPE";
            break;
        case SCANNER:
            return "SCANNER";
            break;
        case FADE:
            return "FADE";
            break;
        case BLINK:
            return "BLINK";
            break;
        case ON_AND_OFF:
            return "ON_AND_OFF";
            break;
        case PULSATING:
            return "PULSATING";
            break;
        case LOADING:
            return "LOADING";
            break;
        case STEP:
            return "STEP";
            break;
    }
}


//creates file for Arduino, and eventually compile and upload file to Arduino
void DisplayWindow::on_createArduinoButton_clicked()
{
    QDir dir = QDir::current();
    while(dir.dirName() != "GUI_Code")
    {
        dir.cdUp();
    }
    dir.cd("LEDS/src/ledarduinofile");
    QString directory = dir.path();
    string file = QString(directory + "/ledarduinofile.ino").toStdString();
    int size = vecOfStructures->size();
    codeConverter.create(*vecOfStructures, getNumModules() , size, file);
   // system("platformio run -d ~/Documents/GitHub/Modular-LED-HRI-/GUI_Code/LEDS");
    system("/opt/arduino-1.6.9/arduino --board arduino:avr:mega --port /dev/ttyACM1 --upload /home/lwathieu/Documents/GitHub/Modular-LED-HRI-/GUI_Code/LEDS/src/ledarduinofile/ledarduinofile.ino");
    //system("platformio run");
}


//Asks for directory and calls writeCppFile
void DisplayWindow::on_createCppCode_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if (dir == "")
        return;
    string file = QString(dir + "/ledcppfile.cpp").toStdString();
    writeCppFile(file);
}

int DisplayWindow::getNumModules()
{
    int numberModules = 0;
    for (int p = 0; p < vecOfStructures->size(); p++)
    {
        int groupLength = vecOfStructures->at(p).grouplength;
        int highestID = vecOfStructures->at(p).group[groupLength-1];
        if ((highestID+1) > numberModules)
            numberModules = highestID + 1;
    }
    return numberModules;
}

//saves a cpp file with "path" path and name. CPP file uses the library to call
//all the patterns specified by user in GUI. similar to creating Arduino file
void DisplayWindow::writeCppFile(string path)
{
    //print setup to front of file
    ofstream ofile(path.c_str());
    ofile << "#include <fstream>\n#include <string>\n#include <LightParameter.h>\n#include <NeoPixelCodeConverter.h>\n#include <vector>\n\n";
    ofile << "using namespace std;\n\n";
    ofile << "NeoPixelCodeConverter b;\nvector<LightParameter> a;\n\n";
    ofile << "int main()\n{\n\n";
    ofile<<"int* ";
    //writes to file code which will create array of IDs, initialize a pattern,
    //change Ids in array, initialize another pattern, etc.
    for(int t = 0; t < vecOfStructures->size(); t++)
    {
        uint32_t c1 = vecOfStructures->at(t).Color1;
        uint32_t c2 = vecOfStructures->at(t).Color1;

        ofile<<"arr = new int["<<vecOfStructures->at(t).grouplength<<"] {";
        for( int j = 0; j < vecOfStructures->at(t).grouplength; j++)
        {
            ofile<<vecOfStructures->at(t).group[j]<<", ";
        }
        ofile<<"};\n";

        ofile<< "a.push_back(LightParameter(";
        ofile<< getPattern(vecOfStructures->at(t).pattern).toStdString() << ", ";
        ofile<< getDirection(vecOfStructures->at(t).direction).toStdString() << ", ";
        ofile<< vecOfStructures->at(t).startTime << ", ";
        ofile<< vecOfStructures->at(t).cycles << ", ";
        ofile<< vecOfStructures->at(t).index << ", ";
        ofile<< vecOfStructures->at(t).onTime << ", ";
        ofile<< vecOfStructures->at(t).offTime << ", ";
        ofile<< vecOfStructures->at(t).brightness << ", ";
        ofile<< "b.Color(" <<int(parentForDWin->Red(c1))<<",";
        ofile<< int(parentForDWin->Green(c1))<<",";
        ofile<< int(parentForDWin->Blue(c1))<<"), ";
        ofile<< "b.Color(" <<int(parentForDWin->Red(c2))<<",";
        ofile<< int(parentForDWin->Green(c2))<<",";
        ofile<<int(parentForDWin->Blue(c2))<<"), ";
        ofile<< vecOfStructures->at(t).interval << ", ";
        ofile<< "arr, " << vecOfStructures->at(t).grouplength << "));\n";
        ofile<<"delete [] arr;\n\n";
    }
    ofile<< "b.create(a, " << getNumModules() << ", " << vecOfStructures->size();
    ofile<< ");\n\n}";

    ofile.close();
}

//hides display window and unchecks button in MainWindow
void DisplayWindow::on_closeDisplay_clicked()
{
    hide();
    parentForDWin->CheckDWinButton(false);
}

//when dWindow closed with systems red button, hides window and unchecks button
//in MainWindow
void DisplayWindow::reject()
{
    hide();
    parentForDWin->CheckDWinButton(false);
}

