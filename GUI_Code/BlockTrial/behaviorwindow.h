#ifndef BEHAVIORWINDOW_H
#define BEHAVIORWINDOW_H

#include <QDialog>
#include <ledlabel.h>
#include "Dependencies/LightParameter.h"
#include <QLineEdit>
#include <vector>

namespace Ui {
class BehaviorWindow;
}

class BehaviorWindow : public QDialog
{
    Q_OBJECT

public:
    BehaviorWindow(std::vector<LightParameter> *vecOfStruct,
                   QVector<LEDLabel*> orderedLEDs, QWidget *parent = 0);
    QColor getColor1() {return color1; }
    QColor getColor2() {return color2; }
    void setColor(int whichLED, QColor desiredColor);
    bool UpdateVect();
    void EnableInput(bool enabled, QLineEdit *thisone);
    void setID(int ID) { bWindowID = ID; }
    bool PatternAllowed(int currentID, LightParameter strucToAdd);
    void updateButtonStates(ActivePattern pattern);
    ~BehaviorWindow();

private slots:
    void on_setButton_clicked();
    void on_cancelButton_clicked();
    void on_patternMenuBox_activated(int index);
    void SetUpUi();
    void on_color1Button_clicked();
    void on_color2Button_clicked();
    void on_calcStopTimeLabel_clicked();

private:
    Ui::BehaviorWindow *ui;
    //list of LEDs in the group/pattern
    QVector<LEDLabel*> listLEDs;
    //QColors 1 and 2, patterns with one color change only color1
    QColor color1;
    QColor color2;
    //ID of bWindow (group number). Before group is set, bWindowID = -1 as
    //indicator
    int bWindowID;
    //QVector of LED IDs, in chronological. 
    QVector<int> vectOfIDs;
};

#endif // BEHAVIORWINDOW_H
