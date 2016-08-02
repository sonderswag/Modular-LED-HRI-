#include "linewithtime.h"
#include <QColor>
#include <QDebug>
#include <timeline.h>

TimeLine *parentForLine;

LineWithTime::LineWithTime(QWidget *parent) : QLabel(parent)
{
}

LineWithTime::LineWithTime(int groupID, unsigned long start, unsigned long stop,
                           QColor color, QWidget *parent) : QLabel(parent)
{
    parentForLine = ((TimeLine*)(this->parentWidget()));
    unsigned long maxTime = parentForLine->getMaxStopTime();

    int widthTWindow = 650;
    double leftX = ((double)start/maxTime)*widthTWindow;
    double rightX = ((double)stop/maxTime)*widthTWindow;

    QPixmap *myPix = new QPixmap(QSize(widthTWindow,30));
    myPix->fill(Qt::transparent);
    QPainter paint(myPix);

    paint.setPen(color);
    QLineF line(leftX, 13, rightX, 13);
    QLineF line1(leftX, 14, rightX, 14);
    paint.drawLine(line);
    paint.drawLine(line1);

    paint.setPen(QColor(0, 0, 150));
    paint.drawText(QPoint(leftX/2+rightX/2, 26), QString("Group %1").arg(groupID));

    paint.setPen(Qt::black);
    QRectF r = QRectF(leftX, 0, rightX-leftX, 12);   // QRect r = rect();
    paint.drawText(r, Qt::AlignLeft , QString("%1s").arg(start/1000.0));
    paint.drawText(r, Qt::AlignRight, QString("%1s").arg(stop/1000.0));

    this->setPixmap(*myPix);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

LineWithTime::~LineWithTime()
{
}
