#ifndef LEDLABEL_H
#define LEDLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPainter>

class LEDLabel : public QLabel
{
    Q_OBJECT

public:
    LEDLabel(QWidget *parent = 0);
    LEDLabel(int &LEDCount, QWidget * parent = 0);
    ~LEDLabel();
    QColor getColor() { return LEDColor; }
    int getID(){return ID;}
    void setLED(QColor color, int id);
    //uses setLED to individually set color or ID
    void setColor(QColor color) { setLED(color, ID); }
    void setID(int id) { setLED(LEDColor, id); }
    
    void setShade(bool shade);

private:
    //Stores the current LEDLabel's color
    QColor LEDColor;
    //Stores the current LEDLabel's ID (to be displayed)
    int ID;
};

#endif // LEDLABEL_H
