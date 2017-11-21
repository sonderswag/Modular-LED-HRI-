#ifndef CLICKABLEDISPLAY_H
#define CLICKABLEDISPLAY_H

#include <QTextBrowser>
#include <QMouseEvent>
//#include "mainwindow.h"

class ClickableDisplay : public QTextBrowser
{
    Q_OBJECT
    public:
        ClickableDisplay( QWidget *parent = 0 );
        ~ClickableDisplay();
        int getGroupNum( QString line );


    protected:
        virtual void mousePressEvent( QMouseEvent * event );

    private:

};



#endif // CLICKABLEDISPLAY_H
