#include "ledlabel.h"
#include <QLabel>
#include <QPainter>
const int Offset = 35;

LEDLabel::LEDLabel(QWidget *parent) : QLabel(parent)
{
}

/*
 *
 * Inherits from QLabel: it is a square label with a colored circle inside.
 *
 */
LEDLabel::LEDLabel(int &LEDCount, QWidget *parent) : QLabel(parent)
{
    //setUp the size of label to 32x32, white, and displaying no ID(set ID = -1)
    this->setFixedSize(32, 32);
    this->setLED(QColor(255,255,255), -1);
    //move LED to 35 to the right of previous LED.
    this->move(20 + Offset*LEDCount, 70);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
    LEDCount++;
}

LEDLabel::~LEDLabel()
{
}

//sets shade to on or off. when the led is selected, the color turns a little
//darker to indicate it
void LEDLabel::setShade(bool shade)
{
    if (shade == true)
    {
        //take the label's pixmap and shade it
        QPixmap pixmap = *this->pixmap();
        QPixmap tempPixmap = pixmap;
        QPainter painter;
        painter.begin(&tempPixmap);
        //fill pixmap with a translucent white, to shade it
        painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
        painter.end();
        this->setPixmap(tempPixmap);
    }
    else if (shade == false)
    {
        //revert color to it's stored, intended value. This will unshade any
        //shaded LEDs
        this->setColor(LEDColor);
    }
    this->show();
}

// setLED to given color and ID number
void LEDLabel::setLED(QColor color, int id)
{
    LEDColor = color;
    QPixmap *myPix = new QPixmap(QSize(32,32));
    myPix->fill(Qt::transparent);
    QPainter paint(myPix);

    //change pixmap with painter, set black pen and LEDColor-ed brush
    paint.setPen(Qt::black);
    paint.setBrush(LEDColor);
    //draws a circle with diameter 31
    QRect r = QRect(0, 0, 31, 31);   // QRect r = rect();
    paint.drawEllipse(r);
    //if ID value is valid (positive)
    if (id >= 0)
    {
        ID = id;
        //display the ID in the center of the pixmap
        paint.drawText(r, Qt::AlignCenter, QString("%1").arg(id));
    }
    //if ID value is invalid (negative). ID = -1 is a flag that no ID is 
    //assigned
    else
    {
        ID = id;
        //display nothing in the center of the pixmap
        paint.drawText(r, Qt::AlignCenter, QString(""));
    }
    //set myPix as the current pixmap of the LED
    setPixmap(*myPix);
    show();
}


