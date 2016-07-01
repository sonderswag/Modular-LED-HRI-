#include "mainwindow.h"
#include "dragwidget.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*
    QWidget mainWidget;
    QHBoxLayout *horizontalLayout = new QHBoxLayout(&mainWidget);
*/
//    horizontalLayout->addWidget(new DragWidget);
//   horizontalLayout->addWidget(new DragWidget);
    w.show();

    return a.exec();
}
