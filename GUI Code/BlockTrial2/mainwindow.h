#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>

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

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> LEDs ;
    int ActiveLED;
};




#endif // MAINWINDOW_H
