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
    int  getNumLEDs(){return LEDs.size();}
    void setActiveLED(int n){activeLED = n;}
    int getActiveLED(){return activeLED;}
    void getOrderedLED(LEDLabel* firstLED);
    void enableEditButtons(bool x);
    void selectLED(LEDLabel *desiredLED);
    void updateDisplay() {dWindow->DisplayInfo();}
    void showBWindow(int groupID) {listBehaviorWindows.at(groupID)->show();}
    void clearGroups();
    void deleteGroup(int groupID);
    //unselects all selected LEDs (unshades them and clears the vector)
    void clearSelectedLEDs();
    void setDisplayWindowButton(bool checked);
    long getStopTime(ActivePattern pattern, int startTime,
                                      int cycles, int interval, int onTime,
                                      int offTime, int grouplength, uint32_t color1);
    long getStopTime(LightParameter struc);

    void pushVecOfBWindows(BehaviorWindow *bWindow)
        {listBehaviorWindows.push_back(bWindow);}
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

private:
    Ui::MainWindow *ui;
    QVector<LEDLabel*> LEDs ;
    QVector<LEDLabel*> selectedLEDs ;
    QVector<LEDLabel*> orderedLEDs ;
    int activeLED;
    DisplayWindow *dWindow;
    std::vector<LightParameter> *vectOfData;
    QVector<BehaviorWindow*> listBehaviorWindows;
 //   BehaviorWindow *bWindow;
 //   QPixmap LEDPic = QPixmap(":/images/LED.png");
};




#endif // MAINWINDOW_H
