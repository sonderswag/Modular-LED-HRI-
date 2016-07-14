#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QtWidgets>
#include "ledlabel.h"
#include <behaviorwindow.h>
#include <LightParameter.h>


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
    void setActiveLED(int n){ActiveLED = n;}
    int getActiveLED(){return ActiveLED;}
    void getOrderedLED(LEDLabel* firstLED);
    void enableEditButtons(bool x);
    void selectLED(LEDLabel *desiredLED);
    void clearSelectedLEDs();               //unselects all selected LEDs (unshades them and clears the vector)

    QVector<LEDLabel*> getListLEDs() {return orderedLEDs;}

protected:
    void dragEnterEvent(QDragEnterEvent *event);// Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event);// Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event);// Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event);// Q_DECL_OVERRIDE;

private slots:

    void on_upArrow_clicked();

    void on_downArrow_clicked();


    void on_QuitButton_clicked();

    void on_addFive_clicked();

    void on_deleteFive_clicked();

    void on_LEDNumEdit_editingFinished();

    void on_clearLEDs_clicked();


    void on_actionSelect_Mode_triggered();

    void on_actionMove_and_Add_Mode_triggered();

    void on_DeleteSelectedButton_clicked();

    void on_actionAdd_Connector_triggered();

    void on_resetID_clicked();

    void on_selectAllButton_clicked();

    void on_addBehaviorButton_clicked();

    void on_resetColor_clicked();

    void on_testPushBack_clicked();

private:
    Ui::MainWindow *ui;
    QVector<LEDLabel*> LEDs ;
    QVector<LEDLabel*> selectedLEDs ;
    QVector<LEDLabel*> orderedLEDs ;
    int ActiveLED;
    BehaviorWindow *bWindow;
 //   QPixmap LEDPic = QPixmap(":/images/LED.png");
};




#endif // MAINWINDOW_H
