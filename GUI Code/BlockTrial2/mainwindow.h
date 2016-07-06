#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QtWidgets>

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
    void getClosestLED(QLabel* desiredLED);
    void enableEditButtons(bool x);
    void selectLED(QLabel* desiredLED);
    void clearSelectedLEDs();               //unselects all selected LEDs (unshades them and clears the vector)

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

private:
    QPixmap LEDPic = QPixmap(":/images/LED.png");
    Ui::MainWindow *ui;
    QVector<QLabel*> LEDs ;
    QVector<QLabel*> selectedLEDs ;
    int ActiveLED;
};




#endif // MAINWINDOW_H
