#ifndef TIMELINE_H
#define TIMELINE_H
#include "linewithtime.h"
#include <QDialog>
#include "Dependencies/LightParameter.h"

namespace Ui {
class TimeLine;
}

class TimeLine : public QDialog
{
    Q_OBJECT

public:
    explicit TimeLine(std::vector<LightParameter> *vecOfStruct, QWidget *parent = 0);
    ~TimeLine();
    void MakeLine(int groupID, unsigned long start, unsigned long stop,
                  QColor color);
    void UpdateTimeline();
    void DeleteAllLines();
    unsigned long getMaxStopTime() {return maxStopTime;}
    void reject();

private:
    Ui::TimeLine *ui;
    //QVector list of LineWithTimes to display
    QVector<LineWithTime*> VectOfLineLabels ;
    //stores the maximum stop time out of all patterns, so all lines can be
    //scaled to this size
    unsigned long maxStopTime;
};

#endif // TIMELINE_H
