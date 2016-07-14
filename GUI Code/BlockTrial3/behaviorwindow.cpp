#include "behaviorwindow.h"
#include "ui_behaviorwindow.h"
#include <mainwindow.h>
#include <ledlabel.h>
#include "LightParameter.h"
#include "NeoPixelCodeConverter.h"


const double sliderFactor = 255.0/99;
QVector<LightParameter> *VectorofStructs;
NeoPixelCodeConverter b;

BehaviorWindow::BehaviorWindow(QVector<LightParameter> *vecofStruct, QVector<LEDLabel*> orderedLEDs, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BehaviorWindow)
{
    VectorofStructs = vecofStruct;
    ui->setupUi(this);
    this->listLEDs = orderedLEDs;
    QString list = "IDs: #";
    QString sep = ", #";

    for(int p = 0; p < listLEDs.size(); p++)
    {
        int id = listLEDs.at(p)->getID();
        if(id >= 0)
            list = QString(list + QString::number(id) + sep);
        else
            list = QString(list + QString("NA") + sep);
    }
    list.chop(3);
    ui->ListSelected->setText(list);
    setColor(Qt::black);
}

BehaviorWindow::~BehaviorWindow()
{

    delete ui;
    listLEDs.clear();
    qDebug() << "listLEDs= " << listLEDs;
}

void BehaviorWindow::setColor(QColor desiredColor)
{
    color = desiredColor;
    ui->colorTest->setLEDColor(desiredColor, -1);
    ui->showRGB->setText(QString("RGB = (%1, %2, %3)").arg(desiredColor.red()).arg(desiredColor.green()).arg(desiredColor.blue()));
}

void BehaviorWindow::on_RSlider_sliderReleased()
{
    int r = (ui->RSlider->value()) * sliderFactor;
    setColor(QColor(r, color.green(), color.blue()));
}

void BehaviorWindow::on_GSlider_sliderReleased()
{
    int g = (ui->GSlider->value()) * sliderFactor;
    setColor(QColor(color.red() ,g ,color.blue()));
}

void BehaviorWindow::on_BSlider_sliderReleased()
{
    int b = (ui->BSlider->value()) * sliderFactor;
    setColor(QColor(color.red(), color.green(), b));
}

void BehaviorWindow::on_SetButton_clicked()
{
    for (int i = 0; i < listLEDs.size(); i++)
    {
        listLEDs.at(i)->setLEDColor(color, listLEDs.at(i)->getID());
        listLEDs.at(i)->setShade(true);
    }

    updateVect();

    close();
}

void BehaviorWindow::on_CancelButton_clicked()
{
    close();
}

void BehaviorWindow::updateVect()
{
    uint32_t c = b.Color(color.red(),color.green(),color.blue(),0);
    uint32_t c1 = b.Color(255,0,0,0);
    int ArrayIDs[listLEDs.size()];

    for (int i = 0; i < listLEDs.size(); i++)
    {
        ArrayIDs[i] = listLEDs.at(i)->getID();

    }


    VectorofStructs->push_back(LightParameter(THEATER_CHASE,FORWARD, 5000, 10, 0, 255, 255, c, c1, 500, ArrayIDs, sizeof(ArrayIDs)/4));
    // UpdateData(ActivePattern Pattern, Direction dir, int start, int cycle, int index, int Totalsteps, int Brightness, uint32_t color1, uint32_t color2, unsigned long interval, int g[], int length)
//    qDebug() << "pattern: " << VectorofStructs->at(0).pattern; //Theat
//    qDebug() << "Direction: " << VectorofStructs->at(0).direction;  //Forward
//    qDebug() << "start: " << VectorofStructs->at(0).start_time;  //5000
//    qDebug() << "cycle: " << VectorofStructs->at(0).cycles;     //10
//    qDebug() << "index: " << VectorofStructs->at(0).index; //0
//    qDebug() << "totalsteps: " << VectorofStructs->at(0).totalsteps; //255
//    qDebug() << "Brightness: " << VectorofStructs->at(0).brightness; //255
//    qDebug() << "color1: " << VectorofStructs->at(0).Color1; //color1
//    qDebug() << "color2: " << VectorofStructs->at(0).Color2; //color2
//    qDebug() << "interval: " << VectorofStructs->at(0).interval;//500
//    qDebug() << "ArrayIDs: " << VectorofStructs->at(0).group[0];//
//    qDebug() << "ArrayIDs size: " << VectorofStructs->at(0).grouplength;//




}
