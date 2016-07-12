#include "behaviorwindow.h"
#include "ui_behaviorwindow.h"
#include <mainwindow.h>
#include <ledlabel.h>
const double sliderFactor = 255.0/99;


BehaviorWindow::BehaviorWindow(QVector<LEDLabel*> orderedLEDs, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BehaviorWindow)
{
    ui->setupUi(this);
    this->listLEDs = orderedLEDs;
    QString list = "IDs: #";
    QString sep = ", #";

    for(int p = 0; p < listLEDs.size(); p++)
    {
        list = QString(list + QString::number(listLEDs.at(p)->getID()) + sep);
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
//    qDebug() << "r: " << r << "  g: " << g << "  b: " << b;
    setColor(QColor(r, color.green(), color.blue()));
}

void BehaviorWindow::on_GSlider_sliderReleased()
{
    int g = (ui->GSlider->value()) * sliderFactor;
//    qDebug() << "r: " << r << "  g: " << g << "  b: " << b;
    setColor(QColor(color.red() ,g ,color.blue()));
}

void BehaviorWindow::on_BSlider_sliderReleased()
{
    int b = (ui->BSlider->value()) * sliderFactor;
//    qDebug() << "r: " << r << "  g: " << g << "  b: " << b;
    setColor(QColor(color.red(), color.green(), b));
}

void BehaviorWindow::on_SetButton_clicked()
{
    for (int i = 0; i < listLEDs.size(); i++)
    {
        listLEDs.at(i)->setLEDColor(color, listLEDs.at(i)->getID());
    }
    close();
}

void BehaviorWindow::on_CancelButton_clicked()
{
    close();
}
