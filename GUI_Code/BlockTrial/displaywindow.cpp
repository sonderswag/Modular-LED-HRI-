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

MainWindow *parentForDWin;
std::vector<LightParameter> *vecOfStructures;
NeoPixelCodeConverter codeConverter;


DisplayWindow::DisplayWindow(std::vector<LightParameter> *vecofStruct,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
    vecOfStructures = vecofStruct;
    this->setWindowTitle("View and Edit Groups");
    parentForDWin = (MainWindow*)(this->parentWidget());

}

DisplayWindow::~DisplayWindow()
{
   // MainWindow::;
    qDebug() << "DisplayWindow destructor";
    delete ui;

}

void DisplayWindow::DisplayInfo()
{
    ui->displayInfo->clear();
    for (int m = 0; m < vecOfStructures->size(); m++)
    {
        qDebug() << "got here";
        
        
        PrintNewLn(QString("Group %1 ").arg(m));

        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        format.setForeground(QBrush(QColor(200,0,0)));
        PrintSameLn(format, QString("(EDIT)"));
        PrintSameLn(format, QString("  "));
        PrintSameLn(format, QString("(DELETE)"));

        format.setFontWeight(QFont::Normal);
        format.setForeground(QBrush(Qt::black));
        PrintSameLn(format, QString(" :"));

        QString group = "LEDs: #";
        QString sep = ", #";
        for(int n = 0; n < vecOfStructures->at(m).grouplength; n++)
        {
            QString id = QString::number(vecOfStructures->at(m).group[n]);
            group = QString(group + id + sep);
        }
        group.chop(3);

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
        if (vecOfStructures->at(m).pattern != RAINBOW_CYCLE)
        {
        uint32_t c1 = vecOfStructures->at(m).Color1;
        PrintNewLnTab(QString("Color 1 RGB: (%1, %2,  %3)")
                 .arg(parentForDWin->Red(c1)).arg(parentForDWin->Green(c1))
                      .arg(parentForDWin->Blue(c1)));
        }
        if (vecOfStructures->at(m).Color2 != 0)
        {
            uint32_t c2 = vecOfStructures->at(m).Color2;
            PrintNewLnTab(QString("Color 2 RGB: (%1, %2,  %3)")
                     .arg(parentForDWin->Red(c2)).arg(parentForDWin->Green(c2))
                          .arg(parentForDWin->Blue(c2)));
        }
        PrintNewLn(QString(""));
    }
}

void DisplayWindow::PrintSameLn(QTextCharFormat format, QString printthis)
{
    QTextCursor cursor( ui->displayInfo->textCursor() );
    cursor.setCharFormat(format);
    cursor.insertText(printthis);
    ui->displayInfo->moveCursor(QTextCursor::End);
}


void DisplayWindow::PrintNewLn(QString printthis)
{
    ui->displayInfo->append(printthis);
}

void DisplayWindow::PrintNewLnTab(QString printthis)
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
            return "REVERSE";
            break;
    }
}

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



void DisplayWindow::on_createArduinoButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if (dir == "")
        return;
    string file = QString(dir + "/ledarduinofile.ino").toStdString();
    int size = vecOfStructures->size();

    codeConverter.create(*vecOfStructures, getNumModules() , size, file);

}



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

void DisplayWindow::writeCppFile(string path)
{
    ofstream ofile(path.c_str());
    ofile << "#include <fstream>\n#include <string>\n#include <LightParameter.h>\n#include <NeoPixelCodeConverter.h>\n#include <vector>\n\n";
    ofile << "using namespace std;\n\n";
    ofile << "NeoPixelCodeConverter b;\nvector<LightParameter> a;\n\n";
    ofile << "int main()\n{\n\n";
    ofile<<"int* ";

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

void DisplayWindow::on_closeDisplay_clicked()
{
    hide();
    parentForDWin->CheckDWinButton(false);
}
void DisplayWindow::reject()
{
    hide();
    parentForDWin->CheckDWinButton(false);
  //  QDialog::reject();
}

