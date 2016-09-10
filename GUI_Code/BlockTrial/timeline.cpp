#include "timeline.h"
#include "ui_timeline.h"
#include "linewithtime.h"
#include <QVBoxLayout>
#include "mainwindow.h"

//a Vertical layout
QVBoxLayout *vbl;
//pointer to vector of LightParameters. Will be initialized with
//MainWindow's vector<LightParameter> *vectOfData
std::vector<LightParameter> *vectOfData;
//pointer to mainwindow which called this classd
MainWindow* parentOfTWindow;

/*
 * A Window that simply displays a LineWithTime object for each pattern group.
 * Adds each LineWithTime to the bottom of a vertical Layout. Inherits from 
 * QDialog
 *
 */

TimeLine::TimeLine(std::vector<LightParameter> *vecOfStruct, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeLine)
{
    ui->setupUi(this);
    this->setWindowTitle("Timeline of Patterns");
    //initilize pointer to vector of LightParameters in MainWindow
    vectOfData = vecOfStruct;
    //initialize parentOfTWindow as pointer to Mainwindow that called timeline
    parentOfTWindow = ((MainWindow*)(this->parentWidget()));
    //set up the vertical layout
    vbl = new QVBoxLayout(this);
    vbl->setAlignment(Qt::AlignTop);
}

TimeLine::~TimeLine()
{
    DeleteAllLines();
    delete ui;
}

//erases and redraws all lines, with newest vectOfData
void TimeLine::UpdateTimeline()
{
    //clear the window
    DeleteAllLines();
    maxStopTime = 0;
    //scan through vectOfData and find largest stopTime
    for (int i = 0; i < vectOfData->size(); i++)
    {
        //update maxStopTime if stopTime of this group is larger
        if (maxStopTime < parentOfTWindow->getStopTime(vectOfData->at(i)))
            maxStopTime = parentOfTWindow->getStopTime(vectOfData->at(i));
    }
    
    //Makes a line for every pattern, passing the ID, startTime, stopTime, and
    //color
    for (int i = 0; i < vectOfData->size(); i++)
    {
        int red = parentOfTWindow->Red(vectOfData->at(i).Color1);
        int green = parentOfTWindow->Green(vectOfData->at(i).Color1);
        int blue = parentOfTWindow->Blue(vectOfData->at(i).Color1);
        MakeLine(i, vectOfData->at(i).startTime,
                 parentOfTWindow->getStopTime(vectOfData->at(i)),
                 QColor(red,green,blue));
    }
}

//deallocates all pointers to LineWithTimes and clears VectOfLineLabels QVector
void TimeLine::DeleteAllLines()
{
    for (int i = 0; i < VectOfLineLabels.size(); i++)
    {
        VectOfLineLabels.at(i)->hide();
        delete VectOfLineLabels.at(i);
    }
    VectOfLineLabels.clear();
}

//creates a LineWithTime with specified parameters, adds it to vertical layout,
//shows it, and pushes it to back of QVector of lines
void TimeLine::MakeLine(int groupID, unsigned long start, unsigned long stop,
                   QColor color)
{
    LineWithTime *line = new LineWithTime(groupID, start, stop, color, this);
    vbl->addWidget(line);
    line->show();
    VectOfLineLabels.push_back(line);
}

//overrides functionality of "close window" small red button to uncheck the
//Display Timeline button on mainwindow, then close as normal
void TimeLine::reject()
{
    parentOfTWindow->CheckTWinButton(false);
    QDialog::reject();
}
