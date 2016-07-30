#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include "Dependencies/LightParameter.h"
#include "Dependencies/NeoPixelCodeConverter.h"
#include <QDialog>
#include <vector>
#include <QTextCharFormat>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayWindow(std::vector<LightParameter> *vecofStruct,
                           QWidget *parent = 0);
    ~DisplayWindow();
    void DisplayInfo();
    void PrintNewLn(QString printthis);
    void PrintNewLnTab(QString printthis);
    void PrintSameLn(QTextCharFormat format, QString printthis);
    QString getPattern(int patternID);
    QString getDirection(int dirID);
    void writeCppFile(string path);
    int getNumModules();


private slots:
    void on_createArduinoButton_clicked();

    void on_createCppCode_clicked();

    void on_closeDisplay_clicked();

private:
    Ui::DisplayWindow *ui;
};

#endif // DISPLAYWINDOW_H
