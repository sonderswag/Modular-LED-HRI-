#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ledlabel.h"
#include <QtWidgets>
#include <QFrame>
#include <QVector>
#include <QDebug>
#include <QtMath>


int LEDCount = 0;         //LEDCount is a counter to displace every new LEDIcon created.


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LEDNumEdit->setValidator(new QIntValidator(0, 99, this));
    setMinimumSize(200, 200);
    setAcceptDrops(true);

    //Create the first LED Label
    LEDLabel *LEDIcon = new LEDLabel(LEDCount, this);
    LEDs.push_back(LEDIcon);

    ui->DisplayText->setReadOnly(true);
    ui->DisplayText->setText("Action Information here");
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
    enableEditButtons(false);

    ui->actionMove_and_Add_Mode->setChecked(true);            //Set Mode to Move and Add
    ui->actionSelect_Mode->setChecked(false);
    ui->actionAdd_Connector->setChecked(false);
    ui->menuSetMode->setWindowTitle("Mode: Move and Add");
    enableEditButtons(true);

}

MainWindow::~MainWindow()
{
    delete ui;
    for (int n = 0; n < LEDs.size(); n++)
    {
        delete LEDs.at(n);

    }
    LEDs.clear();
    selectedLEDs.clear();
    orderedLEDs.clear();
}


void MainWindow::addNumLEDs(int n)                  //adds n number of LEDs
{
    for (int p = 0; p < n; p++)
    {
        if (getNumLEDs() < 99)
        {
            LEDLabel *LEDIcon = new LEDLabel(LEDCount, this);
            LEDs.push_back(LEDIcon);
        }
    }

    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}

void MainWindow::deleteNumLEDs(int n)               //deletes n number of LEDs from the back of LEDs Vector
{
    for (int p = 0; p < n; p++)
    {
        if (LEDs.size() == 1){
            delete LEDs.at(LEDs.size()-1);
            LEDs.pop_back();
            LEDCount = 0;
        }
        else if (LEDs.size() > 1)
        {

            delete LEDs.at(LEDs.size()-1);

            LEDs.pop_back();
            --LEDCount;
        }
    }
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}



void MainWindow::selectLED(LEDLabel *desiredLED) //Selects or de-selects specified LED
{
    qDebug() << "Got here1";
    qDebug() << selectedLEDs;
    QPixmap pixmap = *desiredLED->pixmap();

    for (int m = selectedLEDs.size() - 1 ; m >= 0; --m)
    {
        qDebug() << "Got here2";
        qDebug() << selectedLEDs;
        if (selectedLEDs.at(m) == desiredLED)
        {
            desiredLED->setLEDColor(QColor(255, 255, 0), desiredLED->getID());
            desiredLED->show();

            selectedLEDs.erase(selectedLEDs.begin() + m);
            qDebug() << "Got here3";
            qDebug() << selectedLEDs;
            return;
        }
    }
    qDebug() << "Got here4";
    qDebug() << selectedLEDs;
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    desiredLED->setPixmap(tempPixmap);
    desiredLED->show();
    selectedLEDs.push_back(desiredLED);
    qDebug() << "Got here5";
    qDebug() << selectedLEDs;
}


void MainWindow::clearSelectedLEDs()      //un-selects all selected LEDs
{
    for (int m = selectedLEDs.size() - 1 ; m >= 0; --m)
    {
        //selectLED(selectedLEDs.at(m));
        selectedLEDs.at(m)->setLEDColor(QColor(255, 255, 0), selectedLEDs.at(m)->getID());
        selectedLEDs.at(m)->show();
        selectedLEDs.erase(selectedLEDs.begin() + m);
        qDebug() << "Im Here " << m;
    }
    qDebug() << "got out!!";
    qDebug() << selectedLEDs;
    selectedLEDs.clear();
}



//Menu Items:

void MainWindow::on_actionSelect_Mode_triggered()
{
    if (ui->actionSelect_Mode->isChecked())
    {
        ui->menuSetMode->setWindowTitle("Mode: Select");
        enableEditButtons(false);
        ui->actionMove_and_Add_Mode->setChecked(false);
        ui->actionAdd_Connector->setChecked(false);
    }
}

void MainWindow::on_actionMove_and_Add_Mode_triggered()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        ui->menuSetMode->setWindowTitle("Mode: Move and Add");
        enableEditButtons(true);
        ui->actionSelect_Mode->setChecked(false);
        ui->actionAdd_Connector->setChecked(false);
    }
    else
        enableEditButtons(false);
}

void MainWindow::on_actionAdd_Connector_triggered()
{
    if (ui->actionAdd_Connector->isChecked())
    {
        ui->menuSetMode->setWindowTitle("Mode: Add Connector");
        enableEditButtons(false);
        ui->actionMove_and_Add_Mode->setChecked(false);
        ui->actionSelect_Mode->setChecked(false);
    }
}


void MainWindow::enableEditButtons(bool x)
{
    ui->clearLEDs->setEnabled(x);
    ui->addFive->setEnabled(x);
    ui->deleteFive->setEnabled(x);
    ui->downArrow->setEnabled(x);
    ui->upArrow->setEnabled(x);
}



//button functionality functions:

void MainWindow::on_DeleteSelectedButton_clicked()               //Deletes all selected LEDs
{

    QString output = "Deleted LEDs: #";
    QString sep = ", #";

    QVector<int> deletedLEDs;
    for(int m = 0; m < selectedLEDs.size(); m++)            //run through selectedLEDs, deallocate the memory and delete index
    {
        for(int t = 0;  t < LEDs.size(); t++)
        {
            if (selectedLEDs.at(m) == LEDs.at(t))
            {
                deletedLEDs.push_back(t);
            }
        }
    }
    selectedLEDs.clear();
    qSort(deletedLEDs);

    for (int n = deletedLEDs.size()-1 ; n >= 0 ; --n)
    {
        delete LEDs.at(deletedLEDs.at(n));
        LEDs.erase(LEDs.begin() + deletedLEDs.at(n));
        qDebug() << QString("loop #%1, Deleted ID #%2, LED Size: %3").arg(n).arg(deletedLEDs.at(n)).arg(LEDs.size());
    }

    for(int p = 0; p < deletedLEDs.size(); p++)
    {
        output = QString(output + QString::number(deletedLEDs.at(p)) + sep);
    }
    output.chop(3);
    output = QString(output + QString(". You have %1 LEDs Left.").arg(getNumLEDs()));
    ui->DisplayText->setText(output);

    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
    deletedLEDs.clear();

}





void MainWindow::on_upArrow_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        addNumLEDs(1);
        ui->DisplayText->setText(QString("Added LED #%1").arg(getNumLEDs()));
    }
}

void MainWindow::on_downArrow_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(1);
        ui->DisplayText->setText(QString("Deleted LED #%1").arg(getNumLEDs()+1));
    }
}


void MainWindow::on_QuitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_addFive_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        addNumLEDs(5);
        ui->DisplayText->setText(QString("Added LED's #%1 to #%2").arg(getNumLEDs()-4).arg(getNumLEDs()));
    }
}

void MainWindow::on_deleteFive_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(5);
        ui->DisplayText->setText(QString("Deleted LED's #%1 to #%2").arg(getNumLEDs()+1).arg(getNumLEDs()+5));
    }
}

void MainWindow::on_LEDNumEdit_editingFinished()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        QString displayedText = ui->LEDNumEdit->displayText();
        int desiredNumLEDs = displayedText.toInt();
        if (desiredNumLEDs > getNumLEDs()){
            addNumLEDs(desiredNumLEDs - getNumLEDs());
        }
        else if (desiredNumLEDs < getNumLEDs()){
            deleteNumLEDs(getNumLEDs() - desiredNumLEDs);
        }
    }
    else
        ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}

void MainWindow::on_clearLEDs_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(getNumLEDs());
        ui->DisplayText->setText("Cleared All LEDs");
    }
}

void MainWindow::on_resetID_clicked()
{
    for (int i = 0; i < LEDs.size() ; i++)
    {
        LEDs.at(i)->setLEDColor(LEDs.at(i)->getLEDColor(), -1);
    }
    orderedLEDs.clear();
}


void MainWindow::on_selectAllButton_clicked()
{
    for (int p = 0; p < LEDs.size(); p++)
    {
        for (int t = 0; t < selectedLEDs.size(); t++)
        {
            if (selectedLEDs.at(t) == LEDs.at(p))
            {
                return;
            }
        }
        selectLED(LEDs.at(p));
    }
}




void MainWindow::getOrderedLED(LEDLabel *firstLED)
{
    double firstx = firstLED->x();
    double firsty = firstLED->y();

    qDebug() << "orderedLEDs: " << orderedLEDs;
    qDebug() << "selectedLEDs: " << selectedLEDs;

    selectLED(firstLED);

    orderedLEDs.push_back(firstLED);
    qDebug() << "orderedLEDs: " << orderedLEDs;
    qDebug() << "selectedLEDs: " << selectedLEDs;
    LEDLabel* closestLED;
    double smallestDistance;

    while(selectedLEDs.size() != 0)
    {
        smallestDistance = 10000.0;


        for (int m = 0; m < selectedLEDs.size(); m++)
        {
            double distance = qSqrt(qPow(selectedLEDs.at(m)->x()-firstx, 2) + qPow(selectedLEDs.at(m)->y()-firsty, 2));
            qDebug() << distance;


            if (distance < smallestDistance && distance != 0)
            {
                smallestDistance = distance;
                closestLED = selectedLEDs.at(m);
            }
        }

        qDebug() << "smallest distance: " << smallestDistance;

        orderedLEDs.push_back(closestLED);

        selectLED(closestLED);

        qDebug() << "ClosestLED: " << closestLED;
        qDebug() << "orderedLEDs: " << orderedLEDs;
        qDebug() << "selectedLEDs" << selectedLEDs;

        firstx = closestLED->x();
        firsty = closestLED->y();
    }
    for (int t = 0; t < orderedLEDs.size(); t++)
    {
        orderedLEDs.at(t)->setLEDColor(orderedLEDs.at(t)->getLEDColor(), t);
    }

}

//START CLICKING AND DRAGGING FUNCTIONS

//int
void MainWindow::mousePressEvent(QMouseEvent *event)                  //mouse has been clicked (creates a mouse event with position event->pos()
{

    LEDLabel *child = static_cast<LEDLabel*>(childAt(event->pos()));
    QString PressedClassName = child->metaObject()->className();    // What type of object have you pressed?
    qDebug() << "type: " << PressedClassName;
    QString QLabelType = "LEDLabel";

    if (!child){
        qDebug() << "Got to !Child";
        return;}
    else if (PressedClassName != QLabelType) //Exit if you didn't click a LEDLabel Type
    {
        if (ui->actionSelect_Mode->isChecked())
        {
        clearSelectedLEDs(); //If you press the background instead of LED Label, will clear the selected LEDs
        }
        return;
    }

    for (int m = 0; m < LEDs.size(); m++)
    {
        if(LEDs.at(m) == child)
        {
           setActiveLED(m);   // Which #ID LED we pressed
        }
    }
    ui->DisplayText->setText(QString("Selected LED %1").arg(getActiveLED()));

    QPixmap pixmap = *child->pixmap();


    if (ui->actionSelect_Mode->isChecked())               //In select mode, any label which we click on will be selected or deselected
    {
        selectLED(child);
    }

    else if (ui->actionAdd_Connector->isChecked())         // In this mode, will re-order selectedLEDs in accordance to distance.
                                                            //User selects 1st LED, and the algorithm finds next ones until end of selected group.
    {
        qDebug() << "Got Here";
        if (selectedLEDs.empty() == false){                //Make sure SelectedLEDs isn't empty
            for (int i = 0; i < selectedLEDs.size(); i++)
            {
                if (child == selectedLEDs.at(i))
                {
                    getOrderedLED(child);
                }
            }
        }
    }
    else if (ui->actionMove_and_Add_Mode->isChecked())   //In this mode, a drag is started. Some Code borrowed from "Draggable Icons" Qt Example:
                                                         //http://doc.qt.io/qt-5/qtwidgets-draganddrop-draggableicons-example.html

    {
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos() - child->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos() - child->pos());


        QPixmap tempPixmap = pixmap;
        QPainter painter;
        painter.begin(&tempPixmap);
        painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
        painter.end();

        child->setPixmap(tempPixmap);
        child->show();


        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) != Qt::MoveAction) {
            child->show();
            child->setPixmap(pixmap);
            qDebug() << "didn't work??";

        }
    }
}


void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            event->ignore();
        }
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{

    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            event->ignore();
        }

        ui->DisplayText->setText(QString("Moving LED %1 to (%2,%3)").arg(getActiveLED()+1).arg(event->pos().rx()).arg(event->pos().ry()));
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);

            QPixmap pixmap;
            QPoint offset;
            dataStream >> pixmap >> offset;

            int LEDtoMove = getActiveLED();                //Update new place for ActiveLED
            LEDs.at(LEDtoMove)->setPixmap(pixmap);
            LEDs.at(LEDtoMove)->move(event->pos() - offset);
            LEDs.at(LEDtoMove)->show();
            ui->DisplayText->setText(QString("Dropped LED %1 to (%2,%3)").arg(LEDtoMove + 1).arg(LEDs.at(getActiveLED())->pos().rx()).arg(LEDs.at(getActiveLED())->pos().ry()));

            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            qDebug() << "didn't work!!!!!";
            event->ignore();
        }
    }

}





