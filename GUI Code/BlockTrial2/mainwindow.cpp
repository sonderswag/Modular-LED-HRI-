#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QFrame>
#include <QVector>
#include <QDebug>
int i = 0;

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
    QPixmap pix(":/images/LED.png");
    LEDIcon->setPixmap(pix.scaled(LEDIcon->width(),LEDIcon->height(),Qt::KeepAspectRatio));
    LEDIcon->move(20, 20);         //(100 + 5*i, 100 + 5*i);
    LEDIcon->show();
    LEDIcon->setAttribute(Qt::WA_DeleteOnClose);
    LEDs.push_back(LEDIcon);
    i++;

    ui->DisplayText->setReadOnly(true);
    ui->DisplayText->setText("Moving LED __ to (___,___)");
    ui->LEDNumEdit->setText(QString::number(getNumLEDs()));
}
void MainWindow::addNumLEDs(int n)
{
    for (int p = 0; p < n; p++)
    {
        if (getNumLEDs() < 99)
        {
          QLabel *LEDIcon = new QLabel(this);
            LEDIcon->setFixedSize(35, 35);
            QPixmap pix(":/images/LED.png");
            LEDIcon->setPixmap(pix.scaled(LEDIcon->width(),LEDIcon->height(),Qt::KeepAspectRatio));
            LEDIcon->move(20 + 15*i, 20);
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
}



void MainWindow::on_upArrow_clicked()
{
    addNumLEDs(1);
    ui->DisplayText->setText(QString("Added LED #%1").arg(getNumLEDs()));
}

void MainWindow::on_downArrow_clicked()
{

    deleteNumLEDs(1);
    ui->DisplayText->setText(QString("Deleted LED #%1").arg(getNumLEDs()+1));

}


void MainWindow::on_QuitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_addFive_clicked()
{
    addNumLEDs(5);
    ui->DisplayText->setText(QString("Added LED's #%1 to #%2").arg(getNumLEDs()-4).arg(getNumLEDs()));
}

void MainWindow::on_deleteFive_clicked()
{
    deleteNumLEDs(5);
    ui->DisplayText->setText(QString("Deleted LED's #%1 to #%2").arg(getNumLEDs()+1).arg(getNumLEDs()+5));
}

void MainWindow::on_LEDNumEdit_editingFinished()
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

void MainWindow::on_clearLEDs_clicked()
{
    deleteNumLEDs(getNumLEDs());
    ui->DisplayText->setText("Cleared All LEDs");
}





//START DRAGGING FUNCTIONS

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
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

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
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

void MainWindow::dropEvent(QDropEvent *event)
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


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    QString PressedClassName = child->metaObject()->className();    // What type of object have you pressed?
    QString QLabelType = "QLabel";

    if (!child || PressedClassName != QLabelType){                  //Exit if you didn't click a QLabel Type
        return;}

    for (int m = 0; m < LEDs.size(); m++)
    {
        if(LEDs.at(m) == child)
        {
            setActiveLED(m);
        }
    }


    QPixmap pixmap = *child->pixmap();

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

