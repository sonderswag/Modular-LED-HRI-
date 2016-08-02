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
    QVector<LineWithTime*> VectOfLineLabels ;
    unsigned long maxStopTime;
};

#endif // TIMELINE_H
