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
    QColor getLEDColor(){return LEDColor;}
    int getID(){return ID;}
    void setLEDColor(QColor color, int id); //{LEDColor = color;}
    void setShade(bool shade);
    void setID(int id);

private:
//    QPixmap LEDPic = QPixmap(":/images/LED.png");
    QColor LEDColor;
    int ID;
};

#endif // LEDLABEL_H
