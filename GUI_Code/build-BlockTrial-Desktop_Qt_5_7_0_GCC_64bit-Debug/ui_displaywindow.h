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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <clickabledisplay.h>

QT_BEGIN_NAMESPACE

class Ui_DisplayWindow
{
public:
    QGridLayout *gridLayout;
    ClickableDisplay *displayInfo;
    QPushButton *createArduinoButton;
    QPushButton *createCppCode;
    QPushButton *closeDisplay;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *DisplayWindow)
    {
        if (DisplayWindow->objectName().isEmpty())
            DisplayWindow->setObjectName(QStringLiteral("DisplayWindow"));
        DisplayWindow->resize(650, 400);
        gridLayout = new QGridLayout(DisplayWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        displayInfo = new ClickableDisplay(DisplayWindow);
        displayInfo->setObjectName(QStringLiteral("displayInfo"));

        gridLayout->addWidget(displayInfo, 0, 0, 1, 4);

        createArduinoButton = new QPushButton(DisplayWindow);
        createArduinoButton->setObjectName(QStringLiteral("createArduinoButton"));

        gridLayout->addWidget(createArduinoButton, 1, 3, 1, 1);

        createCppCode = new QPushButton(DisplayWindow);
        createCppCode->setObjectName(QStringLiteral("createCppCode"));

        gridLayout->addWidget(createCppCode, 1, 2, 1, 1);

        closeDisplay = new QPushButton(DisplayWindow);
        closeDisplay->setObjectName(QStringLiteral("closeDisplay"));

        gridLayout->addWidget(closeDisplay, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(DisplayWindow);

        QMetaObject::connectSlotsByName(DisplayWindow);
    } // setupUi

    void retranslateUi(QDialog *DisplayWindow)
    {
        DisplayWindow->setWindowTitle(QApplication::translate("DisplayWindow", "Dialog", 0));
        createArduinoButton->setText(QApplication::translate("DisplayWindow", "Create Arduino File", 0));
        createCppCode->setText(QApplication::translate("DisplayWindow", "Generate C++ Code", 0));
        closeDisplay->setText(QApplication::translate("DisplayWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
