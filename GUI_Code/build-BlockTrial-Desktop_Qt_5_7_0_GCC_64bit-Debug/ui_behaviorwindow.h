/********************************************************************************
** Form generated from reading UI file 'behaviorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEHAVIORWINDOW_H
#define UI_BEHAVIORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <ledlabel.h>

QT_BEGIN_NAMESPACE

class Ui_BehaviorWindow
{
public:
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *listSelected;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *calcStopTimeLabel;
    QLabel *stopTimeLabel;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *startTimeLabel;
    QLabel *intervalLabel;
    QLabel *cyclesLabel;
    QLabel *onTimeLabel;
    QLabel *offTimeLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *startTimeInput;
    QLineEdit *intervalInput;
    QLineEdit *cyclesInput;
    QLineEdit *onTimeInput;
    QLineEdit *offTimeInput;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *patternLabel;
    QComboBox *patternMenuBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *directionLabel;
    QComboBox *directionMenuBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *color1Button;
    LEDLabel *color1Test;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *color2Button;
    LEDLabel *color2Test;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *setButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *BehaviorWindow)
    {
        if (BehaviorWindow->objectName().isEmpty())
            BehaviorWindow->setObjectName(QStringLiteral("BehaviorWindow"));
        BehaviorWindow->resize(715, 272);
        horizontalLayout_8 = new QHBoxLayout(BehaviorWindow);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        listSelected = new QTextBrowser(BehaviorWindow);
        listSelected->setObjectName(QStringLiteral("listSelected"));
        listSelected->setMaximumSize(QSize(100000, 70));

        verticalLayout_6->addWidget(listSelected);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        calcStopTimeLabel = new QPushButton(BehaviorWindow);
        calcStopTimeLabel->setObjectName(QStringLiteral("calcStopTimeLabel"));
        calcStopTimeLabel->setMaximumSize(QSize(150, 20));

        horizontalLayout_7->addWidget(calcStopTimeLabel);

        stopTimeLabel = new QLabel(BehaviorWindow);
        stopTimeLabel->setObjectName(QStringLiteral("stopTimeLabel"));

        horizontalLayout_7->addWidget(stopTimeLabel);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        startTimeLabel = new QLabel(BehaviorWindow);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));

        verticalLayout_3->addWidget(startTimeLabel);

        intervalLabel = new QLabel(BehaviorWindow);
        intervalLabel->setObjectName(QStringLiteral("intervalLabel"));

        verticalLayout_3->addWidget(intervalLabel);

        cyclesLabel = new QLabel(BehaviorWindow);
        cyclesLabel->setObjectName(QStringLiteral("cyclesLabel"));

        verticalLayout_3->addWidget(cyclesLabel);

        onTimeLabel = new QLabel(BehaviorWindow);
        onTimeLabel->setObjectName(QStringLiteral("onTimeLabel"));

        verticalLayout_3->addWidget(onTimeLabel);

        offTimeLabel = new QLabel(BehaviorWindow);
        offTimeLabel->setObjectName(QStringLiteral("offTimeLabel"));

        verticalLayout_3->addWidget(offTimeLabel);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        startTimeInput = new QLineEdit(BehaviorWindow);
        startTimeInput->setObjectName(QStringLiteral("startTimeInput"));

        verticalLayout_2->addWidget(startTimeInput);

        intervalInput = new QLineEdit(BehaviorWindow);
        intervalInput->setObjectName(QStringLiteral("intervalInput"));

        verticalLayout_2->addWidget(intervalInput);

        cyclesInput = new QLineEdit(BehaviorWindow);
        cyclesInput->setObjectName(QStringLiteral("cyclesInput"));

        verticalLayout_2->addWidget(cyclesInput);

        onTimeInput = new QLineEdit(BehaviorWindow);
        onTimeInput->setObjectName(QStringLiteral("onTimeInput"));

        verticalLayout_2->addWidget(onTimeInput);

        offTimeInput = new QLineEdit(BehaviorWindow);
        offTimeInput->setObjectName(QStringLiteral("offTimeInput"));

        verticalLayout_2->addWidget(offTimeInput);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        patternLabel = new QLabel(BehaviorWindow);
        patternLabel->setObjectName(QStringLiteral("patternLabel"));

        horizontalLayout->addWidget(patternLabel);

        patternMenuBox = new QComboBox(BehaviorWindow);
        patternMenuBox->setObjectName(QStringLiteral("patternMenuBox"));

        horizontalLayout->addWidget(patternMenuBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        directionLabel = new QLabel(BehaviorWindow);
        directionLabel->setObjectName(QStringLiteral("directionLabel"));

        horizontalLayout_2->addWidget(directionLabel);

        directionMenuBox = new QComboBox(BehaviorWindow);
        directionMenuBox->setObjectName(QStringLiteral("directionMenuBox"));

        horizontalLayout_2->addWidget(directionMenuBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        color1Button = new QPushButton(BehaviorWindow);
        color1Button->setObjectName(QStringLiteral("color1Button"));
        color1Button->setMinimumSize(QSize(120, 30));
        color1Button->setCheckable(false);
        color1Button->setChecked(false);

        horizontalLayout_4->addWidget(color1Button);

        color1Test = new LEDLabel(BehaviorWindow);
        color1Test->setObjectName(QStringLiteral("color1Test"));
        color1Test->setMinimumSize(QSize(32, 32));
        color1Test->setMaximumSize(QSize(32, 32));

        horizontalLayout_4->addWidget(color1Test);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        color2Button = new QPushButton(BehaviorWindow);
        color2Button->setObjectName(QStringLiteral("color2Button"));
        color2Button->setMinimumSize(QSize(120, 30));
        color2Button->setCheckable(false);

        horizontalLayout_5->addWidget(color2Button);

        color2Test = new LEDLabel(BehaviorWindow);
        color2Test->setObjectName(QStringLiteral("color2Test"));
        color2Test->setMinimumSize(QSize(32, 32));
        color2Test->setMaximumSize(QSize(32, 32));

        horizontalLayout_5->addWidget(color2Test);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        setButton = new QPushButton(BehaviorWindow);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setMinimumSize(QSize(150, 30));

        horizontalLayout_6->addWidget(setButton);

        cancelButton = new QPushButton(BehaviorWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(120, 30));

        horizontalLayout_6->addWidget(cancelButton);


        verticalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(BehaviorWindow);

        QMetaObject::connectSlotsByName(BehaviorWindow);
    } // setupUi

    void retranslateUi(QDialog *BehaviorWindow)
    {
        BehaviorWindow->setWindowTitle(QApplication::translate("BehaviorWindow", "Dialog", 0));
        calcStopTimeLabel->setText(QApplication::translate("BehaviorWindow", "Calculate Stop Time", 0));
        stopTimeLabel->setText(QString());
        startTimeLabel->setText(QApplication::translate("BehaviorWindow", "Input Start Time (ms): ", 0));
        intervalLabel->setText(QApplication::translate("BehaviorWindow", "Input Interval (ms): ", 0));
        cyclesLabel->setText(QApplication::translate("BehaviorWindow", "Input Cycles: ", 0));
        onTimeLabel->setText(QApplication::translate("BehaviorWindow", "On Time (ms):", 0));
        offTimeLabel->setText(QApplication::translate("BehaviorWindow", "Off Time (ms):", 0));
        startTimeInput->setText(QApplication::translate("BehaviorWindow", "0", 0));
        intervalInput->setText(QApplication::translate("BehaviorWindow", "0", 0));
        cyclesInput->setText(QApplication::translate("BehaviorWindow", "0", 0));
        onTimeInput->setText(QApplication::translate("BehaviorWindow", "0", 0));
        offTimeInput->setText(QApplication::translate("BehaviorWindow", "0", 0));
        patternLabel->setText(QApplication::translate("BehaviorWindow", "Select Pattern: ", 0));
        patternMenuBox->setCurrentText(QString());
        directionLabel->setText(QApplication::translate("BehaviorWindow", "Select Direction: ", 0));
        color1Button->setText(QApplication::translate("BehaviorWindow", "Set Color 1", 0));
        color1Test->setText(QString());
        color2Button->setText(QApplication::translate("BehaviorWindow", "Set Color 2", 0));
        color2Test->setText(QString());
        setButton->setText(QApplication::translate("BehaviorWindow", "Set Group Attributes", 0));
        cancelButton->setText(QApplication::translate("BehaviorWindow", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class BehaviorWindow: public Ui_BehaviorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEHAVIORWINDOW_H
