#include "displaywindow.h"
#include "ui_displaywindow.h"
#include <mainwindow.h>
#include <ledlabel.h>
#include "Dependencies/LightParameter.h"
#include "Dependencies/NeoPixelCodeConverter.h"
#include <QtAlgorithms>

#include <vector>

std::vector<LightParameter> *vecOfStructures;
NeoPixelCodeConverter codeConverter;


DisplayWindow::DisplayWindow(std::vector<LightParameter> *vecofStruct,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
    vecOfStructures = vecofStruct;


}

DisplayWindow::~DisplayWindow()
{
   // MainWindow::;
    delete ui;

}

void DisplayWindow::DisplayInfo()
{
    ui->displayInfo->clear();
    for (int m = 0; m < vecOfStructures->size(); m++)
    {
        qDebug() << "got here";
        Print(QString("Group %1:").arg(m));
        QString group = "LEDs: #";
        QString sep = ", #";
        for(int n = 0; n < vecOfStructures->at(m).grouplength; n++)
        {
            QString id = QString::number(vecOfStructures->at(m).group[n]);
            group = QString(group + id + sep);
        }
        group.chop(3);

        PrintTab(group);
        PrintTab(QString("Grouplength: %1")
                 .arg(vecOfStructures->at(m).grouplength));
        PrintTab(QString("Pattern: " +
                         getPattern(vecOfStructures->at(m).pattern)));
        PrintTab(QString("Direction: " +
                         getDirection(vecOfStructures->at(m).direction)));
        PrintTab(QString("Start Time: %1")
                 .arg(vecOfStructures->at(m).start_time));
        PrintTab(QString("Interval: %1")
                 .arg(vecOfStructures->at(m).interval));
        PrintTab(QString("Cycles: %1")
                 .arg(vecOfStructures->at(m).cycles));
        if (vecOfStructures->at(m).pattern != RAINBOW_CYCLE)
        {
        uint32_t c1 = vecOfStructures->at(m).Color1;
        PrintTab(QString("Color 1 RGB: (%1, %2,  %3)")
                 .arg(Red(c1)).arg(Green(c1)).arg(Blue(c1)));
        }
        if (vecOfStructures->at(m).Color2 != 0)
        {
            uint32_t c2 = vecOfStructures->at(m).Color2;
            PrintTab(QString("Color 2 RGB: (%1, %2,  %3)")
                     .arg(Red(c2)).arg(Green(c2)).arg(Blue(c2)));
        }
    }
}


void DisplayWindow::Print(QString printthis)
{
    ui->displayInfo->append(printthis);
}

void DisplayWindow::PrintTab(QString printthis)
{
    QString tab = "      ";
    ui->displayInfo->append(QString(tab + printthis));
}

QString DisplayWindow::getDirection(int dirID)
{
    switch (dirID)
    {
        case FORWARD:
            return "FORWARD";
            break;
        case REVERSE:
            return "Reverse";
            break;
    }
}

QString DisplayWindow::getPattern(int patternID)
{
    switch (patternID)
    {
        case NONE:
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

void DisplayWindow::on_refreshButton_clicked()
{
    DisplayInfo();
}


void DisplayWindow::on_createArduinoButton_clicked()
{
    int numberModules = 0;
    for (int p = 0; p < vecOfStructures->size(); p++)
    {
        int groupLength = vecOfStructures->at(p).grouplength;
        int highestID = vecOfStructures->at(p).group[groupLength-1];
        if ((highestID+1) > numberModules)
            numberModules = highestID + 1;
    }

    qDebug() << "Number of Modules: " << numberModules;
  //  vector<LightParameter> stdVector = vecOfStructures->toStdVector();
    int size = vecOfStructures->size();
    codeConverter.create(*vecOfStructures, numberModules , size);
    qDebug() << "Made File!!";
}
