#include "clickabledisplay.h"
#include <QTextCursor>
#include <QTextBrowser>
#include <QDebug>
#include "displaywindow.h"
#include "mainwindow.h"

// How many non-integer characters in "Group n:" line
const int extraCharacters = 25;
// stores pointer to DisplayWindow that calls this object, and pointer that
// calls that DisplayWindow
DisplayWindow* parentDWindow;
MainWindow* grandparentMWindow;

/*
 *
 * A class inherited from QTextBrowser. It is a TextBrowser that records any
 * words that the user clicks on. If user selects EDIT, the group specified in the
 * line is edited (it's BehaviorWindow is called). If user selects DELETE, 
 * the group is deleted.
 *
 */

ClickableDisplay::ClickableDisplay( QWidget *parent ) : QTextBrowser( parent )
{
    //make it non-editable by the user
    setReadOnly( true );
    parentDWindow = ((DisplayWindow*)(this->parentWidget()));
    grandparentMWindow = ((MainWindow*)(parentDWindow->parentWidget()));
}

ClickableDisplay::~ClickableDisplay()
{
}

//Is called whenever the Display is clicked. event->pos() stores the click's
//position
void ClickableDisplay::mousePressEvent( QMouseEvent * event )
{
    //-1 is a flag that no group is selected
    int selectedGroup = -1;
    qDebug() << "Clicked!!!!";
    //put the cursor whereever the user clicks
    QTextCursor tc = cursorForPosition( event->pos() );
    //select the word under the cursor, and store in strWord
    tc.select( QTextCursor::WordUnderCursor );
    QString strWord = tc.selectedText();
    qDebug() << "word: " << strWord;
    
    if (strWord == "EDIT")
    {
        qDebug() << "Clicked Edit!!";
        //select the whole line that contains the word
        tc.select( QTextCursor::LineUnderCursor );
        QString strLine = tc.selectedText();
        qDebug() << "Your Line: " << strLine;
        //extracts the Pattern's ID number from earlier in the line
        selectedGroup = getGroupNum(strLine);
    }
    else if (strWord == "DELETE")
    {
        qDebug() << "Clicked Delete!!";
        //select the whole line that contains the word
        tc.select( QTextCursor::LineUnderCursor );
        QString strLine = tc.selectedText();
        qDebug() << "Your Line: " << strLine;
        //extracts the Pattern's ID number from earlier in the line
        selectedGroup = getGroupNum(strLine);
    }
    
    qDebug() << "Selected Group: " << selectedGroup;

    //If EDIT is clicked, the corresponding BehaviorWindow for the specific
    //group is shown. the user can then edit the attributes
    if (selectedGroup >= 0 && strWord == "EDIT")
    {
        grandparentMWindow->showBWindow(selectedGroup);
    }
    //If DELETE is clicked, the corresponding group is deleted using
    //MainWindow's "deleteGroup" function
    else if (selectedGroup >= 0 && strWord == "DELETE")
    {
        grandparentMWindow->deleteGroup(selectedGroup);
    }

}

// Extracts the Pattern's ID number from a selected line: an example line is:
// "Group *group number goes here* (EDIT) (DELETE) :".
// extraCharacters is a constant that stores the number of characters other than
// the group number
int ClickableDisplay::getGroupNum(QString line)
{
    //find the number of digits in the number
    int numDigits = line.length() - extraCharacters;
    qDebug() << "Digits: " << numDigits;
    
    QString groupNumString;
    //extracts the numDigit-long string starting after the 6th character
    groupNumString = line.mid(6, numDigits);
    
    //converts groupnumString to an integer and returns it
    return groupNumString.toInt();
}
