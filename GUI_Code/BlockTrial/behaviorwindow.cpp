#include "behaviorwindow.h"
#include "ui_behaviorwindow.h"
#include "mainwindow.h"
#include <ledlabel.h>
#include "Dependencies/NeoPixelCodeConverter.h"
#include "Dependencies/LightParameter.h"
#include <QtAlgorithms>
#include <QColorDialog>
#include <vector>


NeoPixelCodeConverter convertColor;
//pointer to vector of LightParameters (patterns), initialized with mainwindow's
//*vectOfData
std::vector<LightParameter> *vectorOfStructs;
//points to MainWindow that called this
MainWindow *parentForBWin;

/*
 * A Window which allows a user to edit all the attributes of a group. 
 * Also calculates stop time so user can coordinate patterns.
 *
 */

BehaviorWindow::BehaviorWindow(std::vector<LightParameter> *vecOfStruct,
                               QVector<LEDLabel*> orderedLEDs, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BehaviorWindow)
{
    ui->setupUi(this);
    
    parentForBWin = ((MainWindow*)(this->parentWidget()));
    vectorOfStructs = vecOfStruct;
    //initialize bWindowID with -1, to indicate this pattern has not been pushed
    //to vectorOfStructs
    bWindowID = -1;
    
    //sets WindowTitle to Group #
    setWindowTitle(QString("Group #%1").arg(vectorOfStructs->size()));
    listLEDs = orderedLEDs;
    
    //fill vectIDs with IDs from listLEDs
    for (int p = 0; p < listLEDs.size(); p++)
    {
        int id = listLEDs.at(p)->getID();
        vectOfIDs.push_back(id);
    }
    //sort vectOfIDs in ascending order
    qSort(vectOfIDs.begin(), vectOfIDs.begin()+(vectOfIDs.size()));
    
    //output IDs to ui->listSelected
    QString list = "IDs: #";
    QString sep = ", #";
    for (int i = 0; i < vectOfIDs.size(); i++)
    {
        list = QString(list + QString::number(vectOfIDs.at(i)) + sep);
    }
    list.chop(3);
    ui->listSelected->setText(list);

    SetUpUi();
}

BehaviorWindow::~BehaviorWindow()
{
    qDebug() << "BWindow Destructor";
    if (bWindowID >= 0)
    {
        for (int i = 0; i < listLEDs.size(); i++)
        {
            listLEDs.at(i)->setColor(QColor(255, 255, 255));
        }
    }
    listLEDs.clear();
    vectOfIDs.clear();
    delete ui;
}

//set up colors, button states, pattern options, direction options,input options
void BehaviorWindow::SetUpUi()
{
    setColor(1, Qt::white);
    setColor(2, Qt::white);
    ui->color2Test->hide();
    ui->color2Button->hide();

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

    EnableInput(true, ui->startTimeInput);
    EnableInput(true, ui->cyclesInput);
    EnableInput(true, ui->intervalInput);
    EnableInput(true, ui->cyclesInput);
    EnableInput(false, ui->onTimeInput);
    EnableInput(false, ui->offTimeInput);

    // set each input to take a number 0 - 10000000
    ui->startTimeInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->cyclesInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->intervalInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->onTimeInput->setValidator(new QIntValidator(0, 10000000, this));
    ui->offTimeInput->setValidator(new QIntValidator(0, 10000000, this));
}

// sets whichLED to desiredColor
void BehaviorWindow::setColor(int whichLED, QColor desiredColor)
{
    if (whichLED == 1)
    {
        ui->color1Test->setLED(desiredColor, 1);
        color1 = desiredColor;
    }
    else if (whichLED == 2)
    {
        ui->color2Test->setLED(desiredColor, 2);
        color2 = desiredColor;
    }
}

//When hit set behavior button,updates vector if valid pattern, sets the colors,
//unselects the LEDs, updates display and updates timeline
void BehaviorWindow::on_setButton_clicked()
{
    if (UpdateVect())  //returns true and updates vector if valid pattern
    {
        for (int i = 0; i < listLEDs.size(); i++)
        {
            listLEDs.at(i)->setColor(color1);
        }
        parentForBWin->clearSelectedLEDs();
        parentForBWin->updateDisplay();
        parentForBWin->updateTimeline();
        close();
    }
}

//Closes the BehaviorWindow, and deletes it if ID = -1 (not in the vector)
void BehaviorWindow::on_cancelButton_clicked()
{
    close();
    if (bWindowID == -1)
    {
        parentForBWin->clearSelectedLEDs();
        this->~BehaviorWindow();
    }
}

//updates Vector with current info in GUI inputs. returns true and updates if
//everything is ok, returns false and does not update if there are overlapping
//patterns with same IDs
bool BehaviorWindow::UpdateVect()
{
    //First, record the users inputs and store them in variables
    
    int arrayIDs[listLEDs.size()];
    int arrayLength = listLEDs.size();
    for (int i = 0; i < arrayLength; i++)
    {
        arrayIDs[i] = vectOfIDs.at(i);
        qDebug() << QString("group at %1: ").arg(i) << arrayIDs[i];

    }

    int currentPatInt = ui->patternMenuBox->currentIndex();
    ActivePattern pat = (ActivePattern)(currentPatInt);

    Direction dir = (Direction)(ui->directionMenuBox->currentIndex());

    unsigned long startTime = (ui->startTimeInput->text()).toLong();

    unsigned long interval = (ui->intervalInput->text()).toLong();

    //if number of cycles not editable, set cycles to default "0'
    unsigned long cyc;
    if (!(ui->cyclesInput->isReadOnly()))
    {
        cyc = (ui->cyclesInput->text()).toLong();
    }
    else
        cyc = 0;

    uint32_t c1;
    uint32_t c2;
    //Set c1 and c2 to 0 if they aren't visible to user
    if (ui->color1Test->isVisible())
        c1 = convertColor.Color(color1.red(),color1.green(), color1.blue(),0);
    else
        c1 = 0;

    if (ui->color2Test->isVisible())
        c2 = convertColor.Color(color2.red(),color2.green(),color2.blue(),0);
    else
        c2 = 0;

    //set onTime and offTime to 0 if read only (if pattern does not require)
    unsigned long onTime;
    unsigned long offTime;
    if (ui->onTimeInput->isReadOnly())
        onTime = 0;
    else
        onTime = (ui->onTimeInput->text()).toLong();
    
    if (ui->offTimeInput->isReadOnly())
        offTime = 0;
    else
        offTime = (ui->offTimeInput->text()).toLong();

    //Later, user could potentially choose brightness
    int index = 0;
    int brightness = 255;

    //If patterns not allowed (overlaps with same IDs), then return false wthout
    //pushing the pattern to the vecotr of patterns
    if(!PatternAllowed(bWindowID, LightParameter(pat , dir, startTime, cyc,
                                         index, onTime, offTime,
                                         brightness, c1, c2, interval,
                                         arrayIDs, arrayLength)))
    {
        return false;
    }

    //if the pattern added is new (has "new" ID tag of -1), then push back
    //vector of Structures with new pattern. Push back vector of BWindows,
    //and change bWindowID from -1 to its index in vector of patterns
    if (bWindowID == -1)
    {
        vectorOfStructs->push_back(LightParameter(pat , dir, startTime, cyc,
                                                  index, onTime, offTime,
                                                  brightness, c1, c2, interval,
                                                  arrayIDs, arrayLength));
        parentForBWin->pushVecOfBWindows(this);
        bWindowID = vectorOfStructs->size()-1;
    }
    //if pattern we are editing already has an ID (we are editing an existing
    //Pattern), then simply update the values of the pattern in vectorOfStructs
    else if (bWindowID >= 0)
    {
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
    }
    //returns true when the vector has been updated
    return true;
}

//When pattern menu is changed, the chosen option is converted to a pattern
//and the buttons and inputs and LED samples update
void BehaviorWindow::on_patternMenuBox_activated(int index)
{
    ActivePattern pattern = ActivePattern(index);
    updateButtonStates(pattern);
}

//update buttons, inputs, and LED samples with the given pattern
void BehaviorWindow::updateButtonStates(ActivePattern pattern)
{
    if (pattern == RAINBOW_CYCLE)
    {
        ui->color2Button->hide();
        ui->color2Test->hide();
        ui->color1Button->hide();
        color1 = QColor(255,220,220);
        ui->color1Test->hide();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(true, ui->cyclesInput);
    }
    else if (pattern == THEATER_CHASE || pattern == FADE)
    {
        ui->color2Button->show();
        ui->color2Test->show();
        ui->color1Button->show();
        ui->color1Test->show();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(true, ui->cyclesInput);
    }
    else if (pattern == COLOR_WIPE)
    {
        ui->color2Button->hide();
        ui->color2Test->hide();
        ui->color1Button->show();
        ui->color1Test->show();
        EnableInput(false, ui->onTimeInput);
        EnableInput(false, ui->offTimeInput);
        EnableInput(false, ui->cyclesInput);
    }
    else if (pattern == ON_AND_OFF)
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
    QColor currentColor = ui->color1Test->getColor();
    //return the color chosen by user
    QColor chosenColor = dialog.getColor(currentColor, this, "Choose Color!!");
    setColor(1, chosenColor);
}

void BehaviorWindow::on_color2Button_clicked()
{
    QColorDialog dialog;
    QColor currentColor = ui->color2Test->getColor();
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

    for (unsigned int patToTest = 0; patToTest < vectorOfStructs->size(); patToTest++)
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
