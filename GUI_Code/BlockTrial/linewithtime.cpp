#include "linewithtime.h"
#include <QColor>
#include <QDebug>
#include <timeline.h>

//will point to timeline object that called this
TimeLine *parentForLine;

/*
 * A Line that inherits from QLabel. Displays line with color, start time, and
 * stopTime, scaling by taking the max stop time of the patterns for timeline
 *
 */

LineWithTime::LineWithTime(QWidget *parent) : QLabel(parent)
{
}

LineWithTime::LineWithTime(int groupID, unsigned long start, unsigned long stop,
                           QColor color, QWidget *parent) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    //initializes parentForLine as TimeLine pointer to object that called this
    parentForLine = ((TimeLine*)(this->parentWidget()));
    //get max time from timeline class, which is the maximum stop time.
    //This enables us to scale all lines with this max time as maximum length
    unsigned long maxTime = parentForLine->getMaxStopTime();
    
    //width of timeline window.
    int widthTWindow = 650;
    
    //left and right x positions of line. scaled by maxTime and widthTWindow
    double leftX = ((double)start/maxTime)*widthTWindow;
    double rightX = ((double)stop/maxTime)*widthTWindow;

    //create QPixMap pbject with width of timeline window and height of 30,
    //create a QPainter object paint that will fill the QPixMap object
    QPixmap *myPix = new QPixmap(QSize(widthTWindow,30));
    myPix->fill(Qt::transparent);
    QPainter paint(myPix);

    //draw 2 lines (leftx->rightx) of pattern color(2 lines for extra thickness)
    paint.setPen(color);
    QLineF line(leftX, 13, rightX, 13);
    QLineF line1(leftX, 14, rightX, 14);
    paint.drawLine(line);
    paint.drawLine(line1);
 
    //write Group # in dark blue text centered and below the line
    paint.setPen(QColor(0, 0, 150));
    paint.drawText(QPoint(leftX/2+rightX/2, 26), QString("Group %1")
                   .arg(groupID));

    //write start and stop in black on top and at beginning and end of line
    paint.setPen(Qt::black);
    QRectF r = QRectF(leftX, 0, rightX-leftX, 12);
    paint.drawText(r, Qt::AlignLeft , QString("%1s").arg(start/1000.0));
    paint.drawText(r, Qt::AlignRight, QString("%1s").arg(stop/1000.0));

    //Set the picture you just "drew" as pixmap for QLabel picture
    this->setPixmap(*myPix);
}

LineWithTime::~LineWithTime()
{
}
