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
//    void setSliders(QColor c);
    bool UpdateVect();
    void EnableInput(bool enabled, QLineEdit *thisone);
    void setID(int ID) { bWindowID = ID; }
    bool PatternAllowed(int currentID, LightParameter strucToAdd);
//    void EnableSliders(bool enabled);

    ~BehaviorWindow();

private slots:

//    void on_rSlider_valueChanged(int value);

//    void on_gSlider_valueChanged(int value);

//    void on_bSlider_valueChanged(int value);

    void on_setButton_clicked();

    void on_cancelButton_clicked();

    void on_patternMenuBox_activated(int index);

    void SetUpUi();

//    void on_directionMenuBox_activated(int index);

//    void on_color1Button_toggled(bool checked);

//    void on_color2Button_toggled(bool checked);



    void on_color1Button_clicked();

    void on_color2Button_clicked();

    void on_calcStopTimeLabel_clicked();

private:
    Ui::BehaviorWindow *ui;
    QVector<LEDLabel*> listLEDs;
    QColor color1;
    QColor color2;
    int bWindowID;
    QVector<int> vectOfIDs;
 //   LightParameter selectedParameters;
};

#endif // BEHAVIORWINDOW_H
