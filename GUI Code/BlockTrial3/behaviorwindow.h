#ifndef BEHAVIORWINDOW_H
#define BEHAVIORWINDOW_H

#include <QDialog>
#include <ledlabel.h>
//#include <>


namespace Ui {
class BehaviorWindow;
}

class BehaviorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BehaviorWindow(QVector<LEDLabel*> orderedLEDs, QWidget *parent = 0);
    QColor getColor() {return color; }
    void setColor(QColor desiredColor);
    ~BehaviorWindow();

private slots:

    void on_RSlider_sliderReleased();

    void on_GSlider_sliderReleased();

    void on_BSlider_sliderReleased();

    void on_SetButton_clicked();

    void on_CancelButton_clicked();


private:
    Ui::BehaviorWindow *ui;
    QVector<LEDLabel*> listLEDs;
    QColor color;
};

#endif // BEHAVIORWINDOW_H
