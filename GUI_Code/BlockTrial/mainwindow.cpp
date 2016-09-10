#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ledlabel.h"
#include "Dependencies/LightParameter.h"
#include "Dependencies/NeoPixelCodeConverter.h"
#include "displaywindow.h"

#include <QtWidgets>
#include <QFrame>
#include <QVector>
#include <QDebug>
#include <QtMath>
#include <QMessageBox>

//counter to displace every new ledIcon created.
int ledCount = 0;

/*
 * A Window with Different modes to add, move and select LEDs. Coordinates
 * BehaviorWindows, DisplayWindow, and TimeLine. Inherited from QMainWindow
 *
 */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(200, 200);
    setAcceptDrops(true);

    //Limits data entered to integers from 0-999
    ui->ledNumEdit->setValidator(new QIntValidator(0, 999, this));
    ui->lowerBoundSelectLabel->setValidator(new QIntValidator(0, 999, this));
    ui->upperBoundSelectLabel->setValidator(new QIntValidator(0, 999, this));
    //sets up displays and disables
    ui->displayText->setReadOnly(true);
    ui->displayText->setText("Action Information here");
    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
    //Set Mode to Move and Add
    ui->actionMove_and_Add_Mode->setChecked(true);
    ui->actionSelect_Mode->setChecked(false);
    ui->actionAssign_IDs->setChecked(false);
    ui->menuSetMode->setWindowTitle("Mode: Move and Add");
    enableEditButtons(true);

    //Create the first LED Label, push back LEDs (list of pointers to all LEDs
    //in the app)
    LEDLabel *ledIcon = new LEDLabel(ledCount, this);
    LEDs.push_back(ledIcon);

    //declare private member pointer variables vectOfData, dWindow, timeline.
    vectOfData = new std::vector<LightParameter>;
    dWindow = new DisplayWindow(vectOfData , this);
    dWindow->setModal(false);
    timeline = new TimeLine(vectOfData, this);
    timeline->setModal(false);
}

//clears and deallocates everything
MainWindow::~MainWindow()
{
    clearGroups();
    clearSelectedLEDs();
    dWindow->close();
    timeline->close();
    orderedLEDs.clear();
    deleteNumLEDs(getNumLEDs());
    listBehaviorWindows.clear();
    vectOfData->clear();
    delete vectOfData;
    LEDs.clear();
    delete ui;
}

//adds n number of LEDs (without IDs), pushes to back of LEDs vector
void MainWindow::addNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        if (getNumLEDs() < 999)
        {
            LEDLabel *ledIcon = new LEDLabel(ledCount, this);
            LEDs.push_back(ledIcon);
        }
    }
    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
}

//deletes n number of LEDs from the back of LEDs Vector
void MainWindow::deleteNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        if (LEDs.size() == 0)
        {
            ledCount = 0;
            break;
        }
        //delete an LED from the back of LEDs
        delete LEDs.at(LEDs.size()-1);
        LEDs.pop_back();
        --ledCount;
    }
    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
}


//Selects or de-selects specified LED (if unselected, selects and vice versa)
//Includes shading or unshading the LED to indicated if selected
void MainWindow::selectLED(LEDLabel *desiredLED)
{
    for (int m = selectedLEDs.size() - 1 ; m >= 0; --m)
    {
        //if LED already selected, unselects it
        if (selectedLEDs.at(m) == desiredLED)
        {
            desiredLED->setShade(false);
            selectedLEDs.erase(selectedLEDs.begin() + m);
            return;
        }
    }
    //if LED not selected, selects it
    desiredLED->setShade(true);
    selectedLEDs.push_back(desiredLED);
}

//unselects all selected LEDs (unshades them and clears the vector)
void MainWindow::clearSelectedLEDs()
{
    for (int m = selectedLEDs.size() - 1 ; m >= 0; --m)
    {
        selectedLEDs.at(m)->setShade(false);
        selectedLEDs.at(m)->show();
        selectedLEDs.erase(selectedLEDs.begin() + m);
    }
    selectedLEDs.clear();
}

//Menu Items:
void MainWindow::on_actionSelect_Mode_triggered()
{
    //if select mode is activated, disable edit buttons and uncheck other modes
    if (ui->actionSelect_Mode->isChecked())
    {
        ui->menuSetMode->setWindowTitle("Mode: Select");
        enableEditButtons(false);
        ui->actionMove_and_Add_Mode->setChecked(false);
        ui->actionAssign_IDs->setChecked(false);
    }
}

void MainWindow::on_actionMove_and_Add_Mode_triggered()
{
    //if move mode is activated, enable edit buttons and uncheck other modes
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        ui->menuSetMode->setWindowTitle("Mode: Move and Add");
        enableEditButtons(true);
        ui->actionSelect_Mode->setChecked(false);
        ui->actionAssign_IDs->setChecked(false);
    }
    else
        enableEditButtons(false);
}

void MainWindow::on_actionAssign_IDs_triggered()
{
    //if assign ID mode is activated, disable edit buttons and uncheck other
    //modes
    if (ui->actionAssign_IDs->isChecked())
    {
        ui->menuSetMode->setWindowTitle("Mode: Add Connector");
        enableEditButtons(false);
        ui->actionMove_and_Add_Mode->setChecked(false);
        ui->actionSelect_Mode->setChecked(false);
    }
}

//enables or disables the ability to edit the number of LEDs
void MainWindow::enableEditButtons(bool x)
{
    ui->clearLEDs->setEnabled(x);
    ui->addFive->setEnabled(x);
    ui->deleteFive->setEnabled(x);
    ui->downArrow->setEnabled(x);
    ui->upArrow->setEnabled(x);
    ui->ledNumEdit->setReadOnly(!x);
}

//Deletes all selected LEDs
void MainWindow::on_deleteSelectedButton_clicked()
{
    QString output = "Deleted LEDs: #";
    QString sep = ", #";
    //records index in LEDs Qvector of deleted LEDs
    QVector<int> deletedLEDs;
    //run through selectedLEDs, deallocate the memory and delete index
    for(int m = 0; m < selectedLEDs.size(); m++)
    {
        for(int t = 0;  t < LEDs.size(); t++)
        {
            //records index of all LEDs that are selected
            if (selectedLEDs.at(m) == LEDs.at(t))
            {
                deletedLEDs.push_back(t);
            }
        }
    }
    selectedLEDs.clear();
    //orders indexes into ascending order
    qSort(deletedLEDs);
    //starting at higher indexes and going down, deallocate and designated
    //index from LEDs. this makes sure that subsequent LEDs do not shift indexes
    for (int n = deletedLEDs.size()-1 ; n >= 0 ; --n)
    {
        delete LEDs.at(deletedLEDs.at(n));
        LEDs.erase(LEDs.begin() + deletedLEDs.at(n));
    }
    //Add Each LEDs index to output QString
    for(int p = 0; p < deletedLEDs.size(); p++)
    {
        output = QString(output + QString::number(deletedLEDs.at(p)) + sep);
    }
    output.chop(3);
    output = QString(output + QString(". You have %1 LEDs Left.")
                     .arg(getNumLEDs()));
    ui->displayText->setText(output);
    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
    deletedLEDs.clear();
}

//When hit up arrow (and in move and add mode), add 1 LED
void MainWindow::on_upArrow_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        addNumLEDs(1);
        ui->displayText->setText(QString("Added LED #%1").arg(getNumLEDs()));
    }
}

//When hit down arrow (and in move and add mode), delete 1 LED
void MainWindow::on_downArrow_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(1);
        ui->displayText->setText(QString("Deleted LED #%1")
                                 .arg(getNumLEDs()+1));
    }
}

//QuitApplication when quit button hit
void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}

//When hit add 5 button (and in move and add mode), add 5 LEDs
void MainWindow::on_addFive_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        addNumLEDs(5);
        ui->displayText->setText(QString("Added LED's #%1 to #%2")
                                 .arg(getNumLEDs()-4).arg(getNumLEDs()));
    }
}

//When hit delete 5 button (and in move and add mode), delete 5 LEDs
void MainWindow::on_deleteFive_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(5);
        ui->displayText->setText(QString("Deleted LED's #%1 to #%2")
                                 .arg(getNumLEDs()+1).arg(getNumLEDs()+5));
    }
}

//When user finishes editing ledNumEdit input
void MainWindow::on_ledNumEdit_editingFinished()
{
    //when add and move mode, add or delete correct number of LEDs
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        QString displayedText = ui->ledNumEdit->displayText();
        int desiredNumLEDs = displayedText.toInt();
        if (desiredNumLEDs > getNumLEDs()){
            addNumLEDs(desiredNumLEDs - getNumLEDs());
        }
        else if (desiredNumLEDs < getNumLEDs()){
            deleteNumLEDs(getNumLEDs() - desiredNumLEDs);
        }
    }
    //If not add and move mode, change text back to number of LEDs
    else
        ui->ledNumEdit->setText(QString::number(getNumLEDs()));
}

// hit "CLEAR"- deletes all groups and the LEDs
void MainWindow::on_clearLEDs_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        clearGroups();
        updateTimeline();
        updateDisplay();
        selectedLEDs.clear();
        orderedLEDs.clear();
        deleteNumLEDs(getNumLEDs());
        ui->displayText->setText("Cleared All LEDs");
    }
}

// hit "Reset IDs"- sets all IDs to -1, which makes them not display
void MainWindow::on_resetID_clicked()
{
    for (int i = 0; i < LEDs.size() ; i++)
    {
        LEDs.at(i)->setID(-1);
    }
    orderedLEDs.clear();
}

//hit "Select all" button- goes through LEDs and sets all to unselected
void MainWindow::on_selectAllButton_clicked()
{
    for (int p = 0; p < LEDs.size(); p++)
    {
        bool selected = false;
        for (int t = 0; t < selectedLEDs.size(); t++)
        {
            //if selected, do nothing and go onto checking next one
            if (selectedLEDs.at(t) == LEDs.at(p))
            {
                selected = true;
                break;
            }
        }
        //if not selected, select
        if (selected == false)
            selectLED(LEDs.at(p));
    }
}

// assigns IDs to all selected LEDs with the given first LED. Gives first LED
// (the one clicked) ID #0, and assigns all LEDs after based on proximity to
// previous LED
void MainWindow::getOrderedLED(LEDLabel *firstLED)
{
    //store x and y of the LED we are working with (current LED)
    double currentx = firstLED->x();
    double currenty = firstLED->y();
    //unselect first LED (because it is part of the selected group)
    selectLED(firstLED);
    //add first LED to vector of LEDs with IDs
    orderedLEDs.push_back(firstLED);
    //pointer that will point to next closest LED after current LED
    LEDLabel* closestLED;
    //double that will hold the distance from currentLED to closestLED
    double smallestDistance;

    //until all LEDs have been IDed and unselected (loops through each selected
    //LED)
    while(selectedLEDs.size() != 0)
    {
        //initialize smallestDistance to something high to make sure it is
        //bigger than the ACTUAL smallest distance between current LED and
        //closest LED
        smallestDistance = 1000000.0;
        //loops through all selectedLEDS to find the closest to current LED
        for (int m = 0; m < selectedLEDs.size(); m++)
        {
            //stores distance between current LED(firstLED) and the selected LED
            double distance = qSqrt(qPow(selectedLEDs.at(m)->x()-currentx, 2) +
                                    qPow(selectedLEDs.at(m)->y()-currenty, 2));
            //checks if that is smallest distance and makes sure distance does
            //not equal 0, which would mean the selected LED IS the current LED
            if (distance < smallestDistance && distance != 0)
            {
                //set smallestDistance and closestLED if the distance is smaller
                smallestDistance = distance;
                closestLED = selectedLEDs.at(m);
            }
        }
        //now that closestLED is determined, push back orderedLEDs with it.
        //unselect closestLED, and set currentx and currenty to closestLED
        //position (move on to searching for next closest LED)
        orderedLEDs.push_back(closestLED);
        selectLED(closestLED);
        currentx = closestLED->x();
        currenty = closestLED->y();
    }
    //set IDs to all orderedLEDs (index of orderedLEDs is ID)
    for (int t = 0; t < orderedLEDs.size(); t++)
    {
        orderedLEDs.at(t)->setID(t);
    }
}

//START CLICKING AND DRAGGING FUNCTIONS

//Triggered when mouse has been clicked (creates a mouse event with position
//event->pos()). This function senses when you click a LEDLabel, and directs
//what to do depending on which mode we are in.
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //casts the object that was clicked into an LEDLabel pointer called child
    LEDLabel *child = static_cast<LEDLabel*>(childAt(event->pos()));
    //checks the class name of the object you pressed
    QString PressedClassName = child->metaObject()->className();
    QString QLabelType = "LEDLabel";
    //Exits if child was not created
    if (!child){
        return;}

    //Exit if you didn't click a LEDLabel Type. If in select mode, clicking the
    //background instead of LED Label will clear the selected LEDs
    if (PressedClassName != QLabelType)
    {
        if (ui->actionSelect_Mode->isChecked())
            clearSelectedLEDs();
        return;
    }
    
    //check which LED from LEDs was clicked: set activeLED to that index of LEDs
    //now LEDs.at(getActiveLED()) points to the same LED as child
    for (int m = 0; m < LEDs.size(); m++)
    {
        if(LEDs.at(m) == child)
           setActiveLED(m);   // Which number LED we pressed
    }
    ui->displayText->setText(QString("Selected LED %1").arg(getActiveLED()));

    //In select mode, any label which we click on will be selected or deselected
    if (ui->actionSelect_Mode->isChecked())
        selectLED(child);

    // In assign IDs mode, sets LED clicked as ID #0 and sets ID of all other
    // selected LEDs
    else if (ui->actionAssign_IDs->isChecked())
    {
        //User selects 1st LED, and the algorithm finds next ones until end of
        //selected group. makes sure at least one LED is selected
        if (selectedLEDs.empty() == false)
        {
            //starts algorithm only if child is part of selectedLEDs
            // (if first LED is selected)
            for (int i = 0; i < selectedLEDs.size(); i++)
            {
                if (child == selectedLEDs.at(i))
                {
                    getOrderedLED(child);
                    break;
                }
            }
        }
    }

    //In move and add mode, a drag is started. Code primarily borrowed from
    //"Draggable Icons" Qt Example:
    //http://doc.qt.io/qt-5/qtwidgets-draganddrop-draggableicons-example.html
    else if (ui->actionMove_and_Add_Mode->isChecked())
    {
        //initiate a pixmap with child's pixmap
        QPixmap pixmap = *child->pixmap();
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos() - child->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos() - child->pos());

        //shade child while it is being dragged
        child->setShade(true);
        
        //if error in drag, show child and change back to original color
        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) !=
                Qt::MoveAction)
        {
            child->show();
            child->setPixmap(pixmap);
        }
    }
}

//In move and add mode, a drag is started. Code primarily borrowed from
//"Draggable Icons" Qt Example:
//http://doc.qt.io/qt-5/qtwidgets-draganddrop-draggableicons-example.html
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            event->ignore();
        }
    }
}

//In move and add mode, a drag is started. Code primarily borrowed from
//"Draggable Icons" Qt Example:
//http://doc.qt.io/qt-5/qtwidgets-draganddrop-draggableicons-example.html
void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{

    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            event->ignore();
        }

        ui->displayText->setText(QString("Moving LED %1 to (%2,%3)")
                                 .arg(getActiveLED()+1).arg(event->pos().rx())
                                 .arg(event->pos().ry()));
    }
}

//In move and add mode, a drag is started. Code primarily borrowed from
//"Draggable Icons" Qt Example:
//http://doc.qt.io/qt-5/qtwidgets-draganddrop-draggableicons-example.html
void MainWindow::dropEvent(QDropEvent *event)
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        if (event->mimeData()->hasFormat("application/x-dnditemdata"))
        {
            QByteArray itemData =
                    event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);

            QPixmap pixmap;
            QPoint offset;
            dataStream >> pixmap >> offset;

            //Update new position for ActiveLED
            int ledtoMove = getActiveLED();
            LEDs.at(ledtoMove)->setPixmap(pixmap);
            LEDs.at(ledtoMove)->move(event->pos() - offset);
            LEDs.at(ledtoMove)->show();
            ui->displayText->setText(QString("Dropped LED %1 to (%2,%3)")
                                     .arg(ledtoMove + 1)
                                     .arg(LEDs.at(getActiveLED())->pos().rx())
                                     .arg(LEDs.at(getActiveLED())->pos().ry()));

            if (event->source() == this)
            {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            }
            else
                event->acceptProposedAction();
        }
        else
            event->ignore();
    }
}



//When hit add behavior, takes all selected LEDs, check if they have IDs,
//then add open an BehaviorWindow for the pattern.
void MainWindow::on_addBehaviorButton_clicked()
{
    //make sure at least 1 LED selected
    if (selectedLEDs.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "Must Select at least 1 LED");
        return;
    }

    //first assume all selected LEDs have IDs
    bool allLEDsHaveIDs = true;
    //loop through selected LEDs, making sure they have a valid ID (>=0)
    for (int m = 0; m < selectedLEDs.size(); m++)
    {
        if (selectedLEDs.at(m)->getID() < 0)
        {
            allLEDsHaveIDs = false;
            break;
        }
    }
    //return and display warning if not all LEDs have IDs
    if (allLEDsHaveIDs == false)
    {
        QMessageBox::warning(this, "LED ID Problem", "Not all LEDs selected have IDs. Please assign an ID to all LEDs");
        return;
    }
    
    //create new BehaviorWindow for the selected group of LEDs
    BehaviorWindow *bWindow = new BehaviorWindow(vectOfData, selectedLEDs,this);
    //set so only the BehaviorWindow can be used while it is open
    bWindow->setModal(true);
    //move BehaviorWindow to good place, and show
    QPoint here = this->pos();
    bWindow->move(here + QPoint((this->width()-bWindow->width())/2, 300));
    bWindow->show();
}

//Called whenever Display Window is selected
void MainWindow::on_displayWindowButton_toggled(bool checked)
{
    //if selected (if user wants to display), update text, move, and show
    if (checked)
    {
        updateDisplay();
        QPoint here = this->pos();
        dWindow->move(here + QPoint(this->width() + 2, 0));
        dWindow->show();
    }
    //if unselected (user does not want to display), hide Display Window
    else
        dWindow->hide();
}

//whenever reset groups is selected, clears groups, updates timeline+display
void MainWindow::on_resetGroupsButton_clicked()
{
    clearGroups();
}

//clears groups
void MainWindow::clearGroups()
{
    for (int m = vectOfData->size() - 1 ; m >= 0; --m)
    {
        deleteGroup(m);
    }
    for (int y = 0; y < LEDs.size(); y++)
    {
        LEDs.at(y)->setColor(QColor(255, 255, 255));
    }
    listBehaviorWindows.clear();
    vectOfData->clear();
}

//with specified groupID, erases that LightParameter from vectOfData,
//deletes bWindow and erases from listBehaviorWindows, updates IDs of
//remaining bWindows in listBehaviorWindows, and updates display and timeline
void MainWindow::deleteGroup(int groupID)
{
    vectOfData->erase(vectOfData->begin() + groupID);
    delete listBehaviorWindows.at(groupID);
    listBehaviorWindows.erase(listBehaviorWindows.begin() + groupID);
    for (int p = groupID; p < listBehaviorWindows.size(); p++)
    {
        listBehaviorWindows.at(p)->setID(p);
    }
    updateDisplay();
    updateTimeline();
}

//calculates stop time based on pattern parameters (overloaded), returns in ms
unsigned long MainWindow::getStopTime(ActivePattern pattern, int startTime,
                                  int cycles, int interval, int onTime,
                                  int offTime, int grouplength, uint32_t color1)
{
    unsigned long stopTime = 0;
    switch(pattern)
    {
        case RAINBOW_CYCLE:
            stopTime = startTime + (cycles)*(interval);
            break;
        case THEATER_CHASE:
            stopTime = startTime + (cycles)*(interval);
            break;
        case COLOR_WIPE:
            stopTime = startTime + ((interval)*(grouplength));
            break;
        case SCANNER:
            stopTime = startTime + (cycles)*((interval)*(grouplength-1)*2);
            break;
        case FADE:
            stopTime = startTime + (cycles)*(interval);
            break;
        case BLINK:
            stopTime = startTime + (cycles)*2*(interval);
            break;
        case ON_AND_OFF:
            stopTime = startTime + (cycles)*(onTime  + offTime);
            break;
        case PULSATING:
            stopTime = startTime + (cycles)*((interval)*2*
                       max(max(Red(color1),Blue(color1)),Green(color1)));
            break;
        case LOADING:
            stopTime = startTime + (cycles)*((interval)*(grouplength));
            break;
        case STEP:
            stopTime = startTime + (cycles)*((interval)*(grouplength));
            break;
        default:
            break;
    }
    return stopTime;
}

//calculates stop time based on LightParameter (overloaded), returns in ms
unsigned long MainWindow::getStopTime(LightParameter struc)
{
    unsigned long stopTime = 0;
    switch(struc.pattern)
    {
        case RAINBOW_CYCLE:
            stopTime = struc.startTime + (struc.cycles)*(struc.interval);
            break;
        case THEATER_CHASE:
            stopTime = struc.startTime + (struc.cycles)*(struc.interval);
            break;
        case COLOR_WIPE:
            stopTime = struc.startTime + ((struc.interval)*(struc.grouplength));
            break;
        case SCANNER:
            stopTime = struc.startTime + (struc.cycles)*((struc.interval)*(struc.grouplength-1)*2);
            break;
        case FADE:
            stopTime = struc.startTime + (struc.cycles)*(struc.interval);
            break;
        case BLINK:
            stopTime = struc.startTime + (struc.cycles)*2*(struc.interval);
            break;
        case ON_AND_OFF:
            stopTime = struc.startTime + (struc.cycles)*(struc.onTime  + struc.offTime);
            break;
        case PULSATING:
            stopTime = struc.startTime + (struc.cycles)*((struc.interval)*2*
                       max(max(Red(struc.Color1),Blue(struc.Color1)),Green(struc.Color1)));
            break;
        case LOADING:
            stopTime = struc.startTime + (struc.cycles)*((struc.interval)*(struc.grouplength));
            break;
        case STEP:
            stopTime = struc.startTime + (struc.cycles)*((struc.interval)*(struc.grouplength));
            break;
        default:
            break;
    }
    return stopTime;
}

//when select Range button pressed, validates the range then selects all LEDS
//with IDs in that range
void MainWindow::on_selectRangeButton_clicked()
{
    //get lower and upper entries
    QString lowText = ui->lowerBoundSelectLabel->text();
    QString upText = ui->upperBoundSelectLabel->text();
    //Check if Range is valid (neither are empty, and upper is higher than lower
    if ((!(lowText.isEmpty()) && !(upText.isEmpty())) &&
            (upText.toInt() > lowText.toInt()))
    {
        int upInt = upText.toInt();
        int lowInt = lowText.toInt();
        if (orderedLEDs.empty())
        {
            QMessageBox::warning(this, "Warning","Must give IDs to LEDs first");
            return;
        }
        // check if the upper range is too high
        if (upInt > orderedLEDs.size()-1)
        {
            QMessageBox::warning(this, "Warning", "Upper Range is Too High");
            return;
        }
        qDebug() << "Range is Valid";
        clearSelectedLEDs();
        //loop from lower ID to upper ID
        for (int p = lowInt; p <= upInt; p++)
        {
            //assume currentLED not selected
            bool selected = false;
            for (int t = 0; t < selectedLEDs.size(); t++)
            {
                //if the ID is selected, set selected to true
                if (orderedLEDs.at(p) == selectedLEDs.at(t))
                {
                    selected = true;
                    break;
                }
            }
            //only select if LED is unselected
            if (selected == false)
                selectLED(orderedLEDs.at(p));
        }
    }
    //clear user entries, for next entry
    ui->lowerBoundSelectLabel->clear();
    ui->upperBoundSelectLabel->clear();
}

//called whenever open timeline button is toggled
void MainWindow::on_timelineWindowButton_toggled(bool checked)
{
    
    //if button is checked (user wants timeline) update+move+show timeline
    if (checked)
    {
        updateTimeline();
        QPoint here = this->pos();
        timeline->move(here + QPoint(this->width() + 2, dWindow->height()+30));
        timeline->show();
    }
    //if button is un-checked (user does not want timeline), hide timeline.
    else
        timeline->hide();
}

//enables programmer to Check the Dwindow button from another class (for example
//, from DisplayWindow)
void MainWindow::CheckDWinButton(bool toggle)
{
    ui->displayWindowButton->setChecked(toggle);
}

//enables programmer to Check the timelinewindow button from another class (for example
//, from TimeLine)
void MainWindow::CheckTWinButton(bool toggle)
{
    ui->timelineWindowButton->setChecked(toggle);
}
