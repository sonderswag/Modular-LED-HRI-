/********************************************************************************
** Form generated from reading UI file 'displaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <clickabledisplay.h>

QT_BEGIN_NAMESPACE

class Ui_DisplayWindow
{
public:
    ClickableDisplay *displayInfo;
    QPushButton *refreshButton;
    QLabel *label;
    QPushButton *createArduinoButton;
    QPushButton *createCppCode;

    void setupUi(QDialog *DisplayWindow)
    {
        if (DisplayWindow->objectName().isEmpty())
            DisplayWindow->setObjectName(QStringLiteral("DisplayWindow"));
        DisplayWindow->resize(723, 422);
        displayInfo = new ClickableDisplay(DisplayWindow);
        displayInfo->setObjectName(QStringLiteral("displayInfo"));
        displayInfo->setGeometry(QRect(50, 40, 611, 321));
        refreshButton = new QPushButton(DisplayWindow);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(50, 380, 80, 23));
        label = new QLabel(DisplayWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 20, 121, 16));
        createArduinoButton = new QPushButton(DisplayWindow);
        createArduinoButton->setObjectName(QStringLiteral("createArduinoButton"));
        createArduinoButton->setGeometry(QRect(490, 380, 151, 23));
        createCppCode = new QPushButton(DisplayWindow);
        createCppCode->setObjectName(QStringLiteral("createCppCode"));
        createCppCode->setGeometry(QRect(270, 380, 211, 23));

        retranslateUi(DisplayWindow);

        QMetaObject::connectSlotsByName(DisplayWindow);
    } // setupUi

    void retranslateUi(QDialog *DisplayWindow)
    {
        DisplayWindow->setWindowTitle(QApplication::translate("DisplayWindow", "Dialog", 0));
        refreshButton->setText(QApplication::translate("DisplayWindow", "Refresh", 0));
        label->setText(QApplication::translate("DisplayWindow", "Log of Patterns", 0));
        createArduinoButton->setText(QApplication::translate("DisplayWindow", "Create Arduino File", 0));
        createCppCode->setText(QApplication::translate("DisplayWindow", "Generate C++ Code", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
