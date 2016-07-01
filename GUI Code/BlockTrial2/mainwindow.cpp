#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QFrame>
#include <QVector>
#include <QDebug>
int i = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LEDNumEdit->setValidator(new QIntValidator(0, 99, this));
    setMinimumSize(200, 200);
    setAcceptDrops(true);

//    for(int i = 0; i < 10; i++)
//    {
        QLabel *LEDIcon = new QLabel(this);
        int w = LEDIcon->width();
        int h = LEDIcon->height();
        QPixmap pix(":/images/LED.png");
        LEDIcon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        LEDIcon->move(20, 20);         //(100 + 5*i, 100 + 5*i);
        LEDIcon->show();
        LEDIcon->setAttribute(Qt::WA_DeleteOnClose);
        LEDs.push_back(LEDIcon);
        i++;
//    }

}
void MainWindow::addNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        QLabel *LEDIcon = new QLabel(this);
        int w = LEDIcon->width();
        int h = LEDIcon->height();
        QPixmap pix(":/images/LED.png");
        LEDIcon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        LEDIcon->move(20 + 15*i, 20);
        LEDIcon->show();
        LEDIcon->setAttribute(Qt::WA_DeleteOnClose);
        LEDs.push_back(LEDIcon);
        i++;
    }
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}

void MainWindow::deleteNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        if (LEDs.size() == 1){
            delete LEDs.at(LEDs.size()-1);
            LEDs.pop_back();
            i = 0;
        }
        else if (LEDs.size() > 1)
        {
            delete LEDs.at(LEDs.size()-1);
            LEDs.pop_back();
            --i;
        }
    }
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}


MainWindow::~MainWindow()
{
    delete ui;
    for (int n = 0; n < LEDs.size(); i++)
    {
        delete LEDs.at(n);
    }
    LEDs.clear();
}



void MainWindow::on_upArrow_clicked()
{
    addNumLEDs(1);
}

void MainWindow::on_downArrow_clicked()
{
    deleteNumLEDs(1);
}


void MainWindow::on_QuitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_addFive_clicked()
{
    addNumLEDs(5);
}

void MainWindow::on_deleteFive_clicked()
{
    deleteNumLEDs(5);
}

void MainWindow::on_LEDNumEdit_editingFinished()
{
    QString displayedText = ui->LEDNumEdit->displayText();
    int desiredNumLEDs = displayedText.toInt();
    if (desiredNumLEDs > getNumLEDs()){
        addNumLEDs(desiredNumLEDs - getNumLEDs());
    }
    else if (desiredNumLEDs < getNumLEDs()){
        deleteNumLEDs(getNumLEDs() - desiredNumLEDs);
    }

}
