#ifndef LINEWITHTIME_H
#define LINEWITHTIME_H
#include <QLabel>
#include <QPainter>
#include <QColor>
#include <QObject>


class LineWithTime : public QLabel
{
    Q_OBJECT

public:
    LineWithTime(QWidget *parent = 0);
    LineWithTime(int groupID, unsigned long start, unsigned long stop,
                 QColor color, QWidget *parent = 0);
    ~LineWithTime();
};

#endif // LINEWITHTIME_H
