#include "mainwindow.h"
#include "dragwidget.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignLeft,w.size(),
                                      qApp->desktop()->availableGeometry()));
    w.show();
    a.setStyle("Plastique");
    return a.exec();
}
