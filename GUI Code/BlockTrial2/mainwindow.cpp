#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QFrame>
#include <QVector>
#include <QDebug>
int i = 0;
//int i

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LEDNumEdit->setValidator(new QIntValidator(0, 99, this));
    setMinimumSize(200, 200);
    setAcceptDrops(true);


    QLabel *LEDIcon = new QLabel(this);
    LEDIcon->setFixedSize(35, 35);
    LEDIcon->setPixmap(LEDPic.scaled(LEDIcon->width(),LEDIcon->height(),Qt::KeepAspectRatio));
    LEDIcon->move(20, 70);         //(100 + 5*i, 100 + 5*i);
    LEDIcon->show();
    LEDIcon->setAttribute(Qt::WA_DeleteOnClose);
    LEDs.push_back(LEDIcon);
    i++;

    ui->DisplayText->setReadOnly(true);
    ui->DisplayText->setText("Moving LED __ to (___,___)");
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
    enableEditButtons(false);

}
void MainWindow::addNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        if (getNumLEDs() < 99)
        {
          QLabel *LEDIcon = new QLabel(this);
            LEDIcon->setFixedSize(35, 35);
            LEDIcon->setPixmap(LEDPic.scaled(LEDIcon->width(),LEDIcon->height(),Qt::KeepAspectRatio));
            LEDIcon->move(20 + 15*i, 70);
            LEDIcon->show();
            LEDIcon->setAttribute(Qt::WA_DeleteOnClose);
            LEDs.push_back(LEDIcon);
            i++;
        }
    }

    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}

void MainWindow::deleteNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        if (LEDs.size() == 1){
            delete LEDs.at(LEDs.size()-1);
            LEDs.pop_back();
            i = 0;
        }
        else if (LEDs.size() > 1)
        {

            delete LEDs.at(LEDs.size()-1);

            LEDs.pop_back();
            --i;
        }
    }
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}


MainWindow::~MainWindow()
{
    delete ui;
    for (int n = 0; n < LEDs.size(); i++)
    {
        delete LEDs.at(n);

    }
    LEDs.clear();
    selectedLEDs.clear();
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





//START DRAGGING FUNCTIONS

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

            int LEDtoMove = getActiveLED();
            LEDs.at(LEDtoMove)->setPixmap(pixmap);
            LEDs.at(LEDtoMove)->move(event->pos() - offset);
            LEDs.at(LEDtoMove)->show();
            LEDs.at(LEDtoMove)->setAttribute(Qt::WA_DeleteOnClose);
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


void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    QString PressedClassName = child->metaObject()->className();    // What type of object have you pressed?
    QString QLabelType = "QLabel";

    if (!child){                  //Exit if you didn't click a QLabel Type
        qDebug() << "Got to !Child";
        return;}
    else if (PressedClassName != QLabelType)\
    {
        if (ui->actionSelect_Mode->isChecked())
        {
        clearSelectedLEDs();
        }
        return;
    }

    for (int m = 0; m < LEDs.size(); m++)
    {
        if(LEDs.at(m) == child)
        {
           setActiveLED(m);
        }
    }
    ui->DisplayText->setText(QString("Selected LED %1").arg(getActiveLED()));

    QPixmap pixmap = *child->pixmap();


    if (ui->actionSelect_Mode->isChecked())
    {
        selectLED(child);
    }
    else if (ui->actionAdd_Connector->isChecked())               // In this mode, we re-order selectedLEDs in accordance to distance. User selects 1st LED, and the algorithm finds next one until end of selected.
    {
//        getClosestLED(QLabel* desiredLED);
    }
    else if (ui->actionMove_and_Add_Mode->isChecked())
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
    ui->DeleteSelectedButton->setEnabled(x);
}

void MainWindow::on_DeleteSelectedButton_clicked()
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

void MainWindow::selectLED(QLabel* desiredLED)
{

    QPixmap pixmap = *desiredLED->pixmap();

    for (int m = 0; m < selectedLEDs.size(); m++)
    {
        if (selectedLEDs.at(m) == desiredLED)
        {
            desiredLED->setPixmap(LEDPic.scaled(desiredLED->width(),desiredLED->height(),Qt::KeepAspectRatio));
            desiredLED->show();

            selectedLEDs.erase(selectedLEDs.begin() + m);
            return;
        }
    }
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    desiredLED->setPixmap(tempPixmap);
    desiredLED->show();
    selectedLEDs.push_back(desiredLED);
}

void MainWindow::clearSelectedLEDs()
{
    for (int m = 0; m < selectedLEDs.size(); m++)
    {
        selectedLEDs.at(m)->setPixmap(LEDPic.scaled(selectedLEDs.at(m)->width(),selectedLEDs.at(m)->height(),Qt::KeepAspectRatio));
        selectedLEDs.at(m)->show();
    }
    selectedLEDs.clear();
}


