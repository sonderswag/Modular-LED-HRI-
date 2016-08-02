#include "timeline.h"
#include "ui_timeline.h"
#include "linewithtime.h"
#include <QVBoxLayout>
#include "mainwindow.h"

QVBoxLayout *vbl;
std::vector<LightParameter> *vectOfData;
MainWindow* parentOfTWindow;

TimeLine::TimeLine(std::vector<LightParameter> *vecOfStruct, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeLine)
{
    maxStopTime = 0;
    vectOfData = vecOfStruct;
    ui->setupUi(this);
    this->setWindowTitle("Timeline of Patterns");
    parentOfTWindow = ((MainWindow*)(this->parentWidget()));
    vbl = new QVBoxLayout(this);
    vbl->setAlignment(Qt::AlignTop);
}

TimeLine::~TimeLine()
{
    DeleteAllLines();
    delete ui;
}

void TimeLine::UpdateTimeline()
{
    DeleteAllLines();
    maxStopTime = 0;
    //scan through and find largets stopTime
    for (int i = 0; i < vectOfData->size(); i++)
    {
        if (maxStopTime < parentOfTWindow->getStopTime(vectOfData->at(i)))
        {
            maxStopTime = parentOfTWindow->getStopTime(vectOfData->at(i));
        }
    }

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

void TimeLine::DeleteAllLines()
{
    for (int i = 0; i < VectOfLineLabels.size(); i++)
    {
        VectOfLineLabels.at(i)->hide();
        delete VectOfLineLabels.at(i);
    }
    VectOfLineLabels.clear();
}

void TimeLine::MakeLine(int groupID, unsigned long start, unsigned long stop,
                   QColor color)
{
    LineWithTime *line = new LineWithTime(groupID, start, stop, color, this);
    vbl->addWidget(line);
    line->show();
    VectOfLineLabels.push_back(line);
}

void TimeLine::reject()
{
    parentOfTWindow->CheckTWinButton(false);
    QDialog::reject();
}
