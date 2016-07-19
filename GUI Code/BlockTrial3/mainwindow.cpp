#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ledlabel.h"
#include "LightParameter.h"
#include "NeoPixelCodeConverter.h"
#include "displaywindow.h"

#include <QtWidgets>
#include <QFrame>
#include <QVector>
#include <QDebug>
#include <QtMath>
#include <QMessageBox>


int ledCount = 0;         //ledCount is a counter to displace every new ledIcon created.
//QVector<LightParameter> a;
//QVector<LightParameter> *vectOfData = new QVector<LightParameter>;

//dWindow
//bWindow = new BehaviorWindow(vectOfData, selectedLEDs, this);
//NeoPixelCodeConverter b;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ledNumEdit->setValidator(new QIntValidator(0, 99, this));
    setMinimumSize(200, 200);
    setAcceptDrops(true);

    //Create the first LED Label
    LEDLabel *ledIcon = new LEDLabel(ledCount, this);
    LEDs.push_back(ledIcon);

    ui->displayText->setReadOnly(true);
    ui->displayText->setText("Action Information here");
    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
    enableEditButtons(false);

    ui->actionMove_and_Add_Mode->setChecked(true);            //Set Mode to Move and Add
    ui->actionSelect_Mode->setChecked(false);
    ui->actionAdd_Connector->setChecked(false);
    ui->menuSetMode->setWindowTitle("Mode: Move and Add");
    enableEditButtons(true);

    vectOfData = new QVector<LightParameter>;
    dWindow = new DisplayWindow(vectOfData , this);
    dWindow->setModal(false);


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
            LEDLabel *ledIcon = new LEDLabel(ledCount, this);
            LEDs.push_back(ledIcon);
        }
    }

    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
}

void MainWindow::deleteNumLEDs(int n)               //deletes n number of LEDs from the back of LEDs Vector
{
    for (int p = 0; p < n; p++)
    {
        if (LEDs.size() == 1){
            delete LEDs.at(LEDs.size()-1);
            LEDs.pop_back();
            ledCount = 0;
        }
        else if (LEDs.size() > 1)
        {

            delete LEDs.at(LEDs.size()-1);

            LEDs.pop_back();
            --ledCount;
        }
    }
    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
}



void MainWindow::selectLED(LEDLabel *desiredLED) //Selects or de-selects specified LED
{
    qDebug() << "Got here1";
    qDebug() << selectedLEDs;

    for (int m = selectedLEDs.size() - 1 ; m >= 0; --m)
    {
        qDebug() << "Got here2";
        qDebug() << selectedLEDs;
        if (selectedLEDs.at(m) == desiredLED)
        {

            desiredLED->setShade(false);
            selectedLEDs.erase(selectedLEDs.begin() + m);
            qDebug() << "Got here3";
            qDebug() << selectedLEDs;
            return;
        }
    }
    qDebug() << "Got here4";
    qDebug() << selectedLEDs;

    desiredLED->setShade(true);
    selectedLEDs.push_back(desiredLED);
    qDebug() << "Got here5";
    qDebug() << selectedLEDs;
}


void MainWindow::clearSelectedLEDs()      //un-selects all selected LEDs
{
    for (int m = selectedLEDs.size() - 1 ; m >= 0; --m)
    {
        //selectLED(selectedLEDs.at(m));
        selectedLEDs.at(m)->setLEDColor(selectedLEDs.at(m)->getLEDColor(), selectedLEDs.at(m)->getID());
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

void MainWindow::on_deleteSelectedButton_clicked()               //Deletes all selected LEDs
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
    ui->displayText->setText(output);

    ui->ledNumEdit->setText(QString::number(getNumLEDs()));
    deletedLEDs.clear();

}





void MainWindow::on_upArrow_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        addNumLEDs(1);
        ui->displayText->setText(QString("Added LED #%1").arg(getNumLEDs()));
    }
}

void MainWindow::on_downArrow_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(1);
        ui->displayText->setText(QString("Deleted LED #%1").arg(getNumLEDs()+1));
    }
}


void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_addFive_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        addNumLEDs(5);
        ui->displayText->setText(QString("Added LED's #%1 to #%2").arg(getNumLEDs()-4).arg(getNumLEDs()));
    }
}

void MainWindow::on_deleteFive_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(5);
        ui->displayText->setText(QString("Deleted LED's #%1 to #%2").arg(getNumLEDs()+1).arg(getNumLEDs()+5));
    }
}

void MainWindow::on_ledNumEdit_editingFinished()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        QString displayedText = ui->ledNumEdit->displayText();
        int desiredNumLEDs = displayedText.toInt();
        if (desiredNumLEDs > getNumLEDs()){
            addNumLEDs(desiredNumLEDs - getNumLEDs());
        }
        else if (desiredNumLEDs < getNumLEDs()){
            deleteNumLEDs(getNumLEDs() - desiredNumLEDs);
        }
    }
    else
        ui->ledNumEdit->setText(QString::number(getNumLEDs()));
}

void MainWindow::on_clearLEDs_clicked()
{
    if (ui->actionMove_and_Add_Mode->isChecked())
    {
        deleteNumLEDs(getNumLEDs());
        ui->displayText->setText("Cleared All LEDs");
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
        bool selected = false;
        for (int t = 0; t < selectedLEDs.size(); t++)
        {
            if (selectedLEDs.at(t) == LEDs.at(p))
            {
                selected = true;
            }
        }
        if (selected == false)
        {
            selectLED(LEDs.at(p));
        }
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
    ui->displayText->setText(QString("Selected LED %1").arg(getActiveLED()));

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

        child->setShade(true);


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

        ui->displayText->setText(QString("Moving LED %1 to (%2,%3)").arg(getActiveLED()+1).arg(event->pos().rx()).arg(event->pos().ry()));
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

            int ledtoMove = getActiveLED();                //Update new place for ActiveLED
            LEDs.at(ledtoMove)->setPixmap(pixmap);
            LEDs.at(ledtoMove)->move(event->pos() - offset);
            LEDs.at(ledtoMove)->show();
            ui->displayText->setText(QString("Dropped LED %1 to (%2,%3)").arg(ledtoMove + 1).arg(LEDs.at(getActiveLED())->pos().rx()).arg(LEDs.at(getActiveLED())->pos().ry()));

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








void MainWindow::on_addBehaviorButton_clicked()
{
    //Test if all LEDs selected have an ID
    bool allLEDsHaveIDs = true;
    for (int m = 0; m < selectedLEDs.size(); m++)
    {
        if (selectedLEDs.at(m)->getID() < 0)
        {
            allLEDsHaveIDs = false;
        }
    }

    if (selectedLEDs.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "Must Select at least 1 LED");
        return;
    }
    else if (allLEDsHaveIDs == false)
    {
        QMessageBox::StandardButton query =
                QMessageBox::question(this, "LED ID Problem",
                                      "Not all LEDs selected have IDs. Continue?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (query == QMessageBox::No){
            return;
        }
    }
    BehaviorWindow bWindow(vectOfData, selectedLEDs, this);
    //Can't access MainWindow with bWindow is open:
    bWindow.setModal(true);
    QPoint here = this->pos();
    bWindow.move(here + QPoint((this->width()-bWindow.width())/2, 300));
    bWindow.exec();

}

void MainWindow::on_resetColor_clicked()
{
    for (int y = 0; y < LEDs.size(); y++)
    {
        LEDs.at(y)->setLEDColor(QColor(255, 255, 255), LEDs.at(y)->getID());
    }
}


void MainWindow::on_displayWindowButton_toggled(bool checked)
{
    if (checked)
    {
        dWindow->DisplayInfo();
        QPoint here = this->pos();
        dWindow->move(here + QPoint(this->width() + 2, 0));
        dWindow->show();
    }
    else
        dWindow->hide();
}

void MainWindow::setDisplayWindowButton(bool checked)
{
    ui->displayWindowButton->setChecked(checked);
}

void MainWindow::on_resetGroupsButton_clicked()
{
    vectOfData->clear();
}
