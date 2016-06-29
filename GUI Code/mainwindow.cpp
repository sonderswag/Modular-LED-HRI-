#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QFile>

//int * const ptr_black = 0x1343ab0;
// const QString:: = "/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png";
//const std::string yellow_circle = "/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
    int w = ui->LEDLabel_1->width();
    int h = ui->LEDLabel_1->height();
    ui->LEDLabel_1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_4->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_6->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_7->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_8->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_9->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->LEDLabel_10->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
//    ui->LEDButton_1->setCheckable(1);
//    ui->LEDButton_2->setCheckable(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LEDButton_1_toggled(bool checked)
{

    if (ui->LEDButton_1->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_1->width();
        int h = ui->LEDLabel_1->height();
        ui->LEDLabel_1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_1->width();
        int h = ui->LEDLabel_1->height();
        ui->LEDLabel_1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }

}

void MainWindow::on_LEDButton_2_toggled(bool checked)
{
    if (ui->LEDButton_2->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_2->width();
        int h = ui->LEDLabel_2->height();
        ui->LEDLabel_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_2->width();
        int h = ui->LEDLabel_2->height();
        ui->LEDLabel_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_3_toggled(bool checked)
{
    if (ui->LEDButton_3->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_3->width();
        int h = ui->LEDLabel_3->height();
        ui->LEDLabel_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_3->width();
        int h = ui->LEDLabel_3->height();
        ui->LEDLabel_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_4_toggled(bool checked)
{
    if (ui->LEDButton_4->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_4->width();
        int h = ui->LEDLabel_4->height();
        ui->LEDLabel_4->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_4->width();
        int h = ui->LEDLabel_4->height();
        ui->LEDLabel_4->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_5_toggled(bool checked)
{
    if (ui->LEDButton_5->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_5->width();
        int h = ui->LEDLabel_5->height();
        ui->LEDLabel_5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_5->width();
        int h = ui->LEDLabel_5->height();
        ui->LEDLabel_5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_6_toggled(bool checked)
{
    if (ui->LEDButton_6->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_6->width();
        int h = ui->LEDLabel_6->height();
        ui->LEDLabel_6->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_6->width();
        int h = ui->LEDLabel_6->height();
        ui->LEDLabel_6->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_7_toggled(bool checked)
{
    if (ui->LEDButton_7->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_7->width();
        int h = ui->LEDLabel_7->height();
        ui->LEDLabel_7->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_7->width();
        int h = ui->LEDLabel_7->height();
        ui->LEDLabel_7->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_8_toggled(bool checked)
{
    if (ui->LEDButton_8->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_8->width();
        int h = ui->LEDLabel_8->height();
        ui->LEDLabel_8->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_8->width();
        int h = ui->LEDLabel_8->height();
        ui->LEDLabel_8->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_9_toggled(bool checked)
{
    if (ui->LEDButton_9->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_9->width();
        int h = ui->LEDLabel_9->height();
        ui->LEDLabel_9->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_9->width();
        int h = ui->LEDLabel_9->height();
        ui->LEDLabel_9->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_LEDButton_10_toggled(bool checked)
{
    if (ui->LEDButton_10->isChecked())
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/yellow_circle.png");
        int w = ui->LEDLabel_10->width();
        int h = ui->LEDLabel_10->height();
        ui->LEDLabel_10->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap pix("/home/lwathieu/Documents/QtProjects/SimpleLEDGUI/images/black_circle.png");
        int w = ui->LEDLabel_10->width();
        int h = ui->LEDLabel_10->height();
        ui->LEDLabel_10->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}






void MainWindow::on_ExportFileButton_clicked()
{

    qDebug() << "clicked EXPORTFILE";

    //GET THE STATE OF ALL BUTTONS

    QFile file("/home/lwathieu/Arduino/LEDProject/LEDProject.ino");
    qDebug() << "Created File";
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    qDebug() << "File Created";

    QTextStream out(&file);


    out << "#include <Adafruit_NeoPixel.h>\n#ifdef __AVR__\n#include <avr/power.h>\n#endif\n\n#define PIN 6\n#define NumLEDs 60\n\n";
    out << "Adafruit_NeoPixel strip = Adafruit_NeoPixel(NumLEDs, PIN, NEO_RGBW + NEO_KHZ800);\n\nvoid setup() {\nstrip.begin();\n";
    out << "strip.show();\n}\nvoid loop() {";
    out <<   "\nstrip.setPixelColor(0, 0, 0, 0, " << ((ui->LEDButton_1->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(1, 0, 0, 0, " << ((ui->LEDButton_2->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(2, 0, 0, 0, " << ((ui->LEDButton_3->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(3, 0, 0, 0, " << ((ui->LEDButton_4->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(4, 0, 0, 0, " << ((ui->LEDButton_5->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(5, 0, 0, 0, " << ((ui->LEDButton_6->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(6, 0, 0, 0, " << ((ui->LEDButton_7->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(7, 0, 0, 0, " << ((ui->LEDButton_8->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(8, 0, 0, 0, " << ((ui->LEDButton_9->isChecked()) ? 127 : 0);
    out << ");\nstrip.setPixelColor(9, 0, 0, 0, " << ((ui->LEDButton_10->isChecked()) ? 127 : 0);
    out << ");\nstrip.show();\n}\n";
    qDebug() << "DONE WRITING FILE";
}



void MainWindow::on_ExportArduinoButton_clicked()
{
    qDebug() << "Create a file here";
}

//void CreateFile()
//{
//    qDebug() << "Entered CreateFile() function";
//}
