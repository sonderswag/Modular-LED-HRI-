#include "ledlabel.h"
#include <QLabel>
#include <QPainter>
const int Offset = 35;


LEDLabel::LEDLabel(int &LEDCount, QWidget *parent) : QLabel(parent)
{

    this->setFixedSize(35, 35);
//    this->setID(0);
    this->setLEDColor(QColor(255,255,0), -1);  //-1 is a flag to clear the text ID
    //this->setPixmap(LEDPic.scaled(this->width(),this->height(),Qt::KeepAspectRatio));
    this->move(20 + Offset*LEDCount, 70);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
//    LEDs.push_back(this);                     //push newest LED pointer to back of LEDIcon vector
    LEDCount++;


}
LEDLabel::~LEDLabel()
{

}
void LEDLabel::setID(int id)
{
//    ID = id;
//    QPixmap *myPix = this->pixmap();
//    QPainter paint(this->pixmap());
//    paint.drawText(Qt::AlignCenter, QString("%1").arg(id));
//    setPixmap(this->pixmap());
//    show();

}

void LEDLabel::setLEDColor(QColor color, int id)
{
    LEDColor = color;
    QPixmap *myPix = new QPixmap(QSize(35,35));
    QPainter paint(myPix);
    paint.setPen(Qt::black);
    paint.setBrush(LEDColor);
    paint.setBackground(Qt::white);
    QRect r = rect();           //QRect(8, 8, 17, 17)
    paint.drawEllipse(r);
    if (id >= 0)
    {
        ID = id;
        paint.drawText(r, Qt::AlignCenter, QString("%1").arg(id));
    }
    else
    {
        paint.drawText(r, Qt::AlignCenter, QString(""));
    }
    setPixmap(*myPix);
    show();

}

