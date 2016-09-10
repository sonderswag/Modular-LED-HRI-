#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QLabel>
#include <QtWidgets>
#include "ledlabel.h"
#include "behaviorwindow.h"
#include "Dependencies/LightParameter.h"
#include "displaywindow.h"
#include "timeline.h"


namespace Ui {
class MainWindow;
class QDragEnterEvent;
class QDropEvent;
class DragWidget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addNumLEDs(int n);
    void deleteNumLEDs(int n);

    void setActiveLED(int n){activeLED = n;}
    void getOrderedLED(LEDLabel* firstLED);
    void enableEditButtons(bool x);
    void selectLED(LEDLabel *desiredLED);
    void updateDisplay() {dWindow->DisplayInfo();}
    void showBWindow(int groupID) {listBehaviorWindows.at(groupID)->show();}
    void clearGroups();
    void deleteGroup(int groupID);
    void clearSelectedLEDs();
    void updateTimeline() {timeline->UpdateTimeline();}
    void pushVecOfBWindows(BehaviorWindow *bWindow)
            {listBehaviorWindows.push_back(bWindow);}
    void CheckDWinButton(bool toggle);
    void CheckTWinButton(bool toggle);

    int  getNumLEDs(){return LEDs.size();}
    unsigned long getStopTime(ActivePattern pattern, int startTime, int cycles,
                     int interval, int onTime, int offTime, int grouplength,
                     uint32_t color1);
    int getActiveLED(){return activeLED;}
    unsigned long getStopTime(LightParameter struc);
    QVector<LEDLabel*> getListLEDs() {return orderedLEDs;}

    // Returns the Red component of a 32-bit color
     uint8_t Red(uint32_t color) { return (color >> 16) & 0xFF; }
     // Returns the Green component of a 32-bit color
    uint8_t Green(uint32_t color) { return (color >> 8) & 0xFF; }
    // Returns the Blue component of a 32-bit color
    uint8_t Blue(uint32_t color) { return color & 0xFF; }


protected:
    void dragEnterEvent(QDragEnterEvent *event);// Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event);// Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event);// Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event);// Q_DECL_OVERRIDE;

private slots:
    void on_upArrow_clicked();
    void on_downArrow_clicked();
    void on_quitButton_clicked();
    void on_addFive_clicked();
    void on_deleteFive_clicked();
    void on_ledNumEdit_editingFinished();
    void on_clearLEDs_clicked();
    void on_actionSelect_Mode_triggered();
    void on_actionMove_and_Add_Mode_triggered();
    void on_deleteSelectedButton_clicked();
    void on_actionAssign_IDs_triggered();
    void on_resetID_clicked();
    void on_selectAllButton_clicked();
    void on_addBehaviorButton_clicked();
    void on_displayWindowButton_toggled(bool checked);
    void on_resetGroupsButton_clicked();
    void on_selectRangeButton_clicked();
    void on_timelineWindowButton_toggled(bool checked);

private:
    //pointer to user interface
    Ui::MainWindow *ui;

    //QVector of pointers to all LED Labels.
    QVector<LEDLabel*> LEDs ;
    //QVector of pointers to all LED Labels that are currently selected.
    QVector<LEDLabel*> selectedLEDs ;
    //QVector of pointers to all LED Labels that have an ID assigned
    QVector<LEDLabel*> orderedLEDs ;
    //ID of the LED currently being dragged or clicked on
    int activeLED;
    //pointer to display window and timeline
    DisplayWindow *dWindow;
    TimeLine *timeline;
    //vector of all LightParameters that are created inside of BehaviorWindow.
    //Stores all patterns that will be uploaded to Arduino eventually
    std::vector<LightParameter> *vectOfData;
    //QVector to store all BehaviorsWindows for each pattern. Make multiple
    //BWindows instead of 1 so that windows "remember" past user entries
    QVector<BehaviorWindow*> listBehaviorWindows;
};




#endif // MAINWINDOW_H
