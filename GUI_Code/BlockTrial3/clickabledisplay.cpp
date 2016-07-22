#include "clickabledisplay.h"
#include <QTextCursor>
#include <QTextBrowser>
#include <QDebug>

//How many non-integer characters in "Group n:" line
const int extraCharacters = 15;

ClickableDisplay::ClickableDisplay( QWidget *parent ) : QTextBrowser( parent )
{
    setReadOnly( true );

}

ClickableDisplay::~ClickableDisplay()
{
}

void ClickableDisplay::mousePressEvent( QMouseEvent * event )
{
    int selectedGroup = -1;
    qDebug() << "Clicked!!!!";
    QTextCursor tc = cursorForPosition( event->pos() );
    tc.select( QTextCursor::WordUnderCursor );
    QString strWord = tc.selectedText();
    qDebug() << "word: " << strWord;
    if (strWord == "EDIT")
    {
        qDebug() << "Clicked Edit!!";
        tc.select( QTextCursor::LineUnderCursor );
        QString strLine = tc.selectedText();
        qDebug() << "Your Line: " << strLine;
        selectedGroup = getGroupNum(strLine);
    }
    qDebug() << "Selected Group: " << selectedGroup;
    // do something with text here...?

}

int ClickableDisplay::getGroupNum(QString line)
{
    int numDigits = line.length() - extraCharacters;
    qDebug() << "Digits: " << numDigits;
    QString groupNumString;
    groupNumString = line.mid(6, numDigits);
    return groupNumString.toInt();
}
