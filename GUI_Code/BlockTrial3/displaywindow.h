#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include "Dependencies/LightParameter.h"
#include <QDialog>
#include <vector>

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
    void Print(QString printthis);
    void PrintTab(QString printthis);
    QString getPattern(int patternID);
    QString getDirection(int dirID);

    // Returns the Red component of a 32-bit color
    uint8_t Red(uint32_t color) { return (color >> 16) & 0xFF; }
    // Returns the Green component of a 32-bit color
    uint8_t Green(uint32_t color) { return (color >> 8) & 0xFF; }
    // Returns the Blue component of a 32-bit color
    uint8_t Blue(uint32_t color) { return color & 0xFF; }

private slots:
    void on_refreshButton_clicked();

    void on_createArduinoButton_clicked();

private:
    Ui::DisplayWindow *ui;
};

#endif // DISPLAYWINDOW_H
