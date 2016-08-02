#include "behaviorwindow.h"
#include "ui_behaviorwindow.h"
#include "mainwindow.h"
#include <ledlabel.h>
#include "Dependencies/LightParameter.h"
#include "Dependencies/NeoPixelCodeConverter.h"
#include <QtAlgorithms>
#include <QColorDialog>
#include <vector>

std::vector<LightParameter> *vectorOfStructs;
NeoPixelCodeConverter convertColor;
MainWindow *parentForBWin;


BehaviorWindow::BehaviorWindow(std::vector<LightParameter> *vecOfStruct,
                               QVector<LEDLabel*> orderedLEDs, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BehaviorWindow)
{
    ui->setupUi(this);
    parentForBWin = ((MainWindow*)(this->parentWidget()));

    bWindowID = -1;
    vectorOfStructs = vecOfStruct;
    this->setWindowTitle(QString("Group #%1").arg(vectorOfStructs->size()));
    this->listLEDs = orderedLEDs;
    QString list = "IDs: #";
    QString sep = ", #";

    for (int p = 0; p < listLEDs.size(); p++)
    {
        int id = listLEDs.at(p)->getID();
        vectOfIDs.push_back(id);
    }

    qSort(vectOfIDs.begin(), vectOfIDs.begin()+(vectOfIDs.size()));

    for (int i = 0; i < vectOfIDs.size(); i++)
    {
        if(vectOfIDs.at(i) >= 0)
            list = QString(list + QString::number(vectOfIDs.at(i)) + sep);
        else
            list = QString(list + QString("NA") + sep);
    }
    list.chop(3);
    ui->listSelected->setText(list);

    SetUpUi();


}

void BehaviorWindow::SetUpUi()
{


    setColor(1, Qt::white);
    setColor(2, Qt::white);
    ui->color2Test->hide();
 //   ui->color1Button->setChecked(true);
    ui->color2Button->hide();


//enum  ActivePattern { NO_PAT, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE,
                      //SCANNER, FADE, BLINK, ON_AND_OFF, PULSATING,
                      //LOADING, STEP};


    ui->patternMenuBox->addItem("NONE");
    ui->patternMenuBox->addItem("RAINBOW_CYCLE");
    ui->patternMenuBox->addItem("THEATER_CHASE");
    ui->patternMenuBox->addItem("COLOR_WIPE");
    ui->patternMenuBox->addItem("SCANNER");
    ui->patternMenuBox->addItem("FADE");
    ui->patternMenuBox->addItem("BLINK");
    ui->patternMenuBox->addItem("ON_AND_OFF");
    ui->patternMenuBox->addItem("PULSATING");
    ui->patternMenuBox->addItem("LOADING");
    ui->patternMenuBox->addItem("STEP");

    ui->directionMenuBox->addItem("FORWARD");
    ui->directionMenuBox->addItem("REVERSE");

    // Set Pattern defaults
 //   selectedParameters = LightParameter(NONE, FORWARD, );

    EnableInput(true, ui->startTimeInput);
    EnableInput(true, ui->cyclesInput);
    EnableInput(true, ui->intervalInput);
    EnableInput(true, ui->cyclesInput);
    EnableInput(false, ui->onTimeInput);
    EnableInput(false, ui->offTimeInput);

    ui->startTimeInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->cyclesInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->intervalInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->onTimeInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->offTimeInput->setValidator(new QIntValidator(0, 10000000, this));

}

BehaviorWindow::~BehaviorWindow()
{
    qDebug() << "Destroying BWindow";
    delete ui;
    for (int i = 0; i < listLEDs.size(); i++)
    {
        listLEDs.at(i)->setLEDColor(QColor(255, 255, 255), listLEDs.at(i)->getID());
    }

    listLEDs.clear();
    vectOfIDs.clear();
    qDebug() << "listLEDs= " << listLEDs;

    qDebug() << "vectOfIDs= " << vectOfIDs;
}

void BehaviorWindow::setColor(int whichLED, QColor desiredColor)
{

    if (whichLED == 1)
    {
        ui->color1Test->setLEDColor(desiredColor, 1);
        color1 = desiredColor;
    }
    if (whichLED == 2)
    {
        ui->color2Test->setLEDColor(desiredColor, 2);
        color2 = desiredColor;
    }

//    ui->showRGB->setText(QString("RGB = (%1, %2, %3)").arg(desiredColor.red())
                                    //.arg(desiredColor.green())
                                    //.arg(desiredColor.blue()));
}

void BehaviorWindow::on_setButton_clicked()
{
    if (UpdateVect())  //returns true and updates vector if valid pattern
    {
        for (int i = 0; i < listLEDs.size(); i++)
        {
            listLEDs.at(i)->setLEDColor(color1, listLEDs.at(i)->getID());
        }
        parentForBWin->clearSelectedLEDs();
        parentForBWin->updateDisplay();
        parentForBWin->updateTimeline();
        close();
    }
}

void BehaviorWindow::on_cancelButton_clicked()
{
    //return the color chosen by user
    close();
    //ui->color2Button->show();
}

bool BehaviorWindow::UpdateVect()
{
    qDebug() << "WindowId = " << bWindowID;
    int arrayIDs[listLEDs.size()];
    int arrayLength = listLEDs.size();

    for (int i = 0; i < arrayLength; i++)
    {
        arrayIDs[i] = vectOfIDs.at(i);
        qDebug() << QString("group at %1: ").arg(i) << arrayIDs[i];

    }

    qDebug() << "grouplength: " << arrayLength;

    int currentPatInt = ui->patternMenuBox->currentIndex();
    ActivePattern pat = (ActivePattern)(currentPatInt);

    qDebug() << "Pattern: " << pat;

    Direction dir = (Direction)(ui->directionMenuBox->currentIndex());
    qDebug() << "Direction: " << dir;

    unsigned long startTime = (ui->startTimeInput->text()).toLong();
    qDebug() << "Start Time: " << startTime;

    unsigned long interval = (ui->intervalInput->text()).toLong();
    qDebug() << "Interval: " << interval;

    unsigned long cyc;
    if (!(ui->cyclesInput->isReadOnly()))
    {
        cyc = (ui->cyclesInput->text()).toLong();
    }
    else
        cyc = 0;
    qDebug() << "Cycles: " << cyc;

    uint32_t c1;
    uint32_t c2;
    if (ui->color1Test->isVisible())
        c1 = convertColor.Color(color1.red(),color1.green(), color1.blue(),0);
    else
        c1 = 0;

    if (ui->color2Test->isVisible())
        c2 = convertColor.Color(color2.red(),color2.green(),color2.blue(),0);
    else
        c2 = 0;

    qDebug() << "Color1: " << c1;
    qDebug() << "Color2: " << c2;

    unsigned long onTime;
    unsigned long offTime;
    if (ui->onTimeInput->isReadOnly())
    {
        onTime = 0;
    }
    else{
        onTime = (ui->onTimeInput->text()).toLong();
        qDebug() << "Ontime: " << onTime;
    }
    if (ui->offTimeInput->isReadOnly())
    {
        offTime = 0;
    }
    else{
        offTime = (ui->offTimeInput->text()).toLong();
        qDebug() << "Offtime: " << offTime;
    }

    int index = 0;
    int brightness = 255;
    qDebug() << "index: " << index;
    qDebug() << "brightness: " << brightness;

    if(!PatternAllowed(bWindowID, LightParameter(pat , dir, startTime, cyc,
                                         index, onTime, offTime,
                                         brightness, c1, c2, interval,
                                         arrayIDs, arrayLength)))
    {
        return false;
    }

    if (bWindowID == -1){
        qDebug() << "About to Push Back vectorOfStructs";
        vectorOfStructs->push_back(LightParameter(pat , dir, startTime, cyc,
                                                  index, onTime, offTime,
                                                  brightness, c1, c2, interval,
                                                  arrayIDs, arrayLength));
       // parentForBWin->
        qDebug() << "Finished Pushing Back vectorOfStructs";
        qDebug() << "about to parentForBWin->pushVecOfBWindows";
        parentForBWin->pushVecOfBWindows(this);
        qDebug() << "finished parentForBWin->pushVecOfBWindows";
        bWindowID = vectorOfStructs->size()-1;
        qDebug() << " finished bWindowID = vectorOfStructs->size()-1;";
    }
    else if (bWindowID >= 0){
        vectorOfStructs->at(bWindowID).pattern = pat;
        vectorOfStructs->at(bWindowID).direction = dir;
        vectorOfStructs->at(bWindowID).startTime = startTime;
        vectorOfStructs->at(bWindowID).cycles = cyc;
        vectorOfStructs->at(bWindowID).index = index;
        vectorOfStructs->at(bWindowID).onTime = onTime;
        vectorOfStructs->at(bWindowID).offTime = offTime;
        vectorOfStructs->at(bWindowID).brightness = brightness;
        vectorOfStructs->at(bWindowID).Color1 = c1;
        vectorOfStructs->at(bWindowID).Color2 = c2;
        vectorOfStructs->at(bWindowID).interval = interval;
        //vectorOfStructs->at(bWindowID).group = arrayIDs;
        //ectorOfStructs->at(bWindowID).grouplength = arrayLength;
    }
    return true;
}

void BehaviorWindow::on_patternMenuBox_activated(int index)
{
  //  0: NONE, 1: RAINBOW_CYCLE,2: THEATER_CHASE,3: COLOR_WIPE,4: SCANNER,
  //  5: FADE,6: BLINK,7: ON_AND_OFF,8: PULSATING,9: LOADING,10: STEP

    if (index == 1)
    {
        ui->color2Button->hide();
        ui->color2Test->hide();
        ui->color1Button->hide();
        color1 = QColor(255,220,220);
        ui->color1Test->hide();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(true, ui->cyclesInput);
//        EnableSliders(false);
    }
    else if (index == 2 || index == 5)
    {
        ui->color2Button->show();
        ui->color2Test->show();
        ui->color1Button->show();
        ui->color1Test->show();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(true, ui->cyclesInput);
    }
    else if (index == 3)
    {
        ui->color2Button->hide();
        ui->color2Test->hide();
        ui->color1Button->show();
        ui->color1Test->show();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(false, ui->cyclesInput);
    }
    else if (index == 7)
    {
        ui->color2Button->hide();
        ui->color2Test->hide();
        ui->color1Button->show();
        ui->color1Test->show();
        EnableInput(true, ui->onTimeInput);
        EnableInput(true, ui->offTimeInput);
        EnableInput(true, ui->cyclesInput);
    }
    else
    {
        ui->color2Button->hide();
        ui->color2Test->hide();
        ui->color1Button->show();
        ui->color1Test->show();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(true, ui->cyclesInput);
    }
}




void BehaviorWindow::EnableInput(bool enabled, QLineEdit *thisone)
{
    if (enabled)
    {
        thisone->setReadOnly(false);
        thisone->setText("0");
    }
    else
    {
       thisone->setText("Disabled");
       thisone->setReadOnly(true);
    }
}




void BehaviorWindow::on_color1Button_clicked()
{
    QColorDialog dialog;
    QColor currentColor = ui->color1Test->getLEDColor();
    //return the color chosen by user
    QColor chosenColor = dialog.getColor(currentColor, this, "Choose Color!!");
    setColor(1, chosenColor);
}

void BehaviorWindow::on_color2Button_clicked()
{
    QColorDialog dialog;
    QColor currentColor = ui->color2Test->getLEDColor();
    //return the color chosen by user
    QColor chosenColor = dialog.getColor(currentColor, this, "Choose Color!!");
    setColor(2, chosenColor);
}

void BehaviorWindow::on_calcStopTimeLabel_clicked()
{
    ActivePattern pat = ActivePattern(ui->patternMenuBox->currentIndex());
    unsigned long start = ui->startTimeInput->text().toLong();
    unsigned long cycle = ui->cyclesInput->text().toLong();
    unsigned long interval = ui->intervalInput->text().toLong();
    unsigned long on = ui->onTimeInput->text().toLong();
    unsigned long off = ui->offTimeInput->text().toLong();
    int length = listLEDs.size();
    uint32_t c1 = convertColor.Color(color1.red(),color1.green(), color1.blue(),0);

    double stop = (parentForBWin->getStopTime(pat, start, cycle, interval,
                                             on, off, length, c1))/1000.0;
    ui->stopTimeLabel->setText(QString("Stop Time = %1 Seconds").arg(stop));
}

//Checks for Overlap errors
bool BehaviorWindow::PatternAllowed(int currentID, LightParameter strucToAdd)
{
    //First assume that the pattern is allowed
    bool patternAllowed = true;

    for (int patToTest = 0; patToTest < vectorOfStructs->size(); patToTest++)
    {
        //dont check for overlap if it is window being edited
        if (patToTest == currentID)
            break;
        bool oneLEDInCommon = false;
        for (int i = 0; i < strucToAdd.grouplength; i++)
        {
            for (int p = 0; p < vectorOfStructs->at(patToTest).grouplength; p++)
            {
                if(strucToAdd.group[i] ==
                    vectorOfStructs->at(patToTest).group[p])
                {
                    oneLEDInCommon = true;
                    break;
                }
            }
            if (oneLEDInCommon)
                break;
        }
        if(oneLEDInCommon)
        {
            //at least one LED in Common, now check overlapping ranges of time
            if((strucToAdd.startTime <=
                   parentForBWin->getStopTime(vectorOfStructs->at(patToTest)))
                    && (vectorOfStructs->at(patToTest).startTime <=
                   parentForBWin->getStopTime(strucToAdd)))
            {
                patternAllowed = false;
                QMessageBox::warning(this, "Warning",
                                     "LEDs in common with an existing group, and there is a time overlap. Group not allowed!!");
                break;
            }
        }
    }
    return patternAllowed;
}
