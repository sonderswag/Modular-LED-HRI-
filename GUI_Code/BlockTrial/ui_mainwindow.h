/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_Mode;
    QAction *actionMove_and_Add_Mode;
    QAction *actionAssign_IDs;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *line_2;
    QPushButton *resetGroupsButton;
    QLineEdit *displayText;
    QPushButton *quitButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lowerBoundSelectLabel;
    QLineEdit *upperBoundSelectLabel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *selectRangeButton;
    QPushButton *resetID;
    QPushButton *deleteSelectedButton;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ledNumEdit;
    QVBoxLayout *verticalLayout;
    QToolButton *upArrow;
    QToolButton *downArrow;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addFive;
    QPushButton *deleteFive;
    QFrame *line;
    QPushButton *clearLEDs;
    QPushButton *addBehaviorButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *selectAllButton;
    QStackedWidget *verticalStackedWidget;
    QWidget *verticalStackedWidgetPage1;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *displayWindowButton;
    QFrame *line_6;
    QMenuBar *menuBar;
    QMenu *menuSetMode;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 505);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionSelect_Mode = new QAction(MainWindow);
        actionSelect_Mode->setObjectName(QStringLiteral("actionSelect_Mode"));
        actionSelect_Mode->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/selectIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_Mode->setIcon(icon);
        actionMove_and_Add_Mode = new QAction(MainWindow);
        actionMove_and_Add_Mode->setObjectName(QStringLiteral("actionMove_and_Add_Mode"));
        actionMove_and_Add_Mode->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/editIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove_and_Add_Mode->setIcon(icon1);
        actionAssign_IDs = new QAction(MainWindow);
        actionAssign_IDs->setObjectName(QStringLiteral("actionAssign_IDs"));
        actionAssign_IDs->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/addBarIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssign_IDs->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 6, 1, 1, 1);

        resetGroupsButton = new QPushButton(centralWidget);
        resetGroupsButton->setObjectName(QStringLiteral("resetGroupsButton"));
        resetGroupsButton->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(resetGroupsButton, 7, 4, 1, 1);

        displayText = new QLineEdit(centralWidget);
        displayText->setObjectName(QStringLiteral("displayText"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayText->sizePolicy().hasHeightForWidth());
        displayText->setSizePolicy(sizePolicy);
        displayText->setMinimumSize(QSize(400, 23));
        displayText->setMaximumSize(QSize(400, 23));
        displayText->setStyleSheet(QStringLiteral("background:#cccccc"));

        gridLayout->addWidget(displayText, 9, 0, 1, 1);

        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(128, 128, 128, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        quitButton->setPalette(palette);
        quitButton->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(quitButton, 9, 4, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lowerBoundSelectLabel = new QLineEdit(centralWidget);
        lowerBoundSelectLabel->setObjectName(QStringLiteral("lowerBoundSelectLabel"));
        lowerBoundSelectLabel->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(lowerBoundSelectLabel);

        upperBoundSelectLabel = new QLineEdit(centralWidget);
        upperBoundSelectLabel->setObjectName(QStringLiteral("upperBoundSelectLabel"));
        upperBoundSelectLabel->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(upperBoundSelectLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        selectRangeButton = new QPushButton(centralWidget);
        selectRangeButton->setObjectName(QStringLiteral("selectRangeButton"));
        selectRangeButton->setMaximumSize(QSize(16777215, 20));
        selectRangeButton->setStyleSheet(QStringLiteral("background:grey;"));

        verticalLayout_3->addWidget(selectRangeButton);


        gridLayout->addLayout(verticalLayout_3, 3, 4, 1, 1);

        resetID = new QPushButton(centralWidget);
        resetID->setObjectName(QStringLiteral("resetID"));
        resetID->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(resetID, 8, 4, 1, 1);

        deleteSelectedButton = new QPushButton(centralWidget);
        deleteSelectedButton->setObjectName(QStringLiteral("deleteSelectedButton"));
        deleteSelectedButton->setEnabled(true);
        deleteSelectedButton->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(deleteSelectedButton, 4, 4, 1, 1);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 5, 3, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ledNumEdit = new QLineEdit(centralWidget);
        ledNumEdit->setObjectName(QStringLiteral("ledNumEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ledNumEdit->sizePolicy().hasHeightForWidth());
        ledNumEdit->setSizePolicy(sizePolicy1);
        ledNumEdit->setMaximumSize(QSize(60, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush6(QColor(0, 0, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush6);
        QBrush brush7(QColor(127, 127, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush7);
        QBrush brush8(QColor(63, 63, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush8);
        QBrush brush9(QColor(0, 0, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush9);
        QBrush brush10(QColor(0, 0, 170, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush10);
        QBrush brush11(QColor(85, 170, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        ledNumEdit->setPalette(palette1);
        QFont font;
        font.setFamily(QStringLiteral("FreeMono"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        ledNumEdit->setFont(font);
        ledNumEdit->setCursor(QCursor(Qt::ArrowCursor));
        ledNumEdit->setMouseTracking(false);
        ledNumEdit->setAutoFillBackground(false);
        ledNumEdit->setMaxLength(3);
        ledNumEdit->setFrame(true);
        ledNumEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(ledNumEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        upArrow = new QToolButton(centralWidget);
        upArrow->setObjectName(QStringLiteral("upArrow"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush12(QColor(239, 235, 231, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush13(QColor(247, 245, 243, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        QBrush brush14(QColor(119, 117, 115, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush14);
        QBrush brush15(QColor(159, 157, 154, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        upArrow->setPalette(palette2);
        upArrow->setFocusPolicy(Qt::NoFocus);
        upArrow->setArrowType(Qt::UpArrow);

        verticalLayout->addWidget(upArrow);

        downArrow = new QToolButton(centralWidget);
        downArrow->setObjectName(QStringLiteral("downArrow"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        downArrow->setPalette(palette3);
        downArrow->setArrowType(Qt::DownArrow);

        verticalLayout->addWidget(downArrow);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addFive = new QPushButton(centralWidget);
        addFive->setObjectName(QStringLiteral("addFive"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        addFive->setPalette(palette4);
        addFive->setStyleSheet(QStringLiteral("background:grey;"));

        verticalLayout_2->addWidget(addFive);

        deleteFive = new QPushButton(centralWidget);
        deleteFive->setObjectName(QStringLiteral("deleteFive"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        deleteFive->setPalette(palette5);
        deleteFive->setStyleSheet(QStringLiteral("background:grey;"));

        verticalLayout_2->addWidget(deleteFive);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 4, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 6, 0, 1, 1);

        clearLEDs = new QPushButton(centralWidget);
        clearLEDs->setObjectName(QStringLiteral("clearLEDs"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        clearLEDs->setPalette(palette6);
        clearLEDs->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(clearLEDs, 1, 4, 1, 1);

        addBehaviorButton = new QPushButton(centralWidget);
        addBehaviorButton->setObjectName(QStringLiteral("addBehaviorButton"));
        addBehaviorButton->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(addBehaviorButton, 7, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 7, 1, 1, 1);

        selectAllButton = new QPushButton(centralWidget);
        selectAllButton->setObjectName(QStringLiteral("selectAllButton"));
        selectAllButton->setStyleSheet(QStringLiteral("background:grey;"));

        gridLayout->addWidget(selectAllButton, 2, 4, 1, 1);

        verticalStackedWidget = new QStackedWidget(centralWidget);
        verticalStackedWidget->setObjectName(QStringLiteral("verticalStackedWidget"));
        verticalStackedWidget->setStyleSheet(QStringLiteral("background:white;border:black;"));
        verticalStackedWidgetPage1 = new QWidget();
        verticalStackedWidgetPage1->setObjectName(QStringLiteral("verticalStackedWidgetPage1"));
        verticalLayout_4 = new QVBoxLayout(verticalStackedWidgetPage1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalStackedWidget->addWidget(verticalStackedWidgetPage1);

        gridLayout->addWidget(verticalStackedWidget, 0, 0, 6, 2);

        displayWindowButton = new QPushButton(centralWidget);
        displayWindowButton->setObjectName(QStringLiteral("displayWindowButton"));
        displayWindowButton->setStyleSheet(QLatin1String("background:grey;\n"
""));
        displayWindowButton->setCheckable(true);
        displayWindowButton->setChecked(false);

        gridLayout->addWidget(displayWindowButton, 8, 0, 1, 1);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 0, 3, 5, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuSetMode = new QMenu(menuBar);
        menuSetMode->setObjectName(QStringLiteral("menuSetMode"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(30, 30));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSetMode->menuAction());
        menuSetMode->addAction(actionMove_and_Add_Mode);
        menuSetMode->addAction(actionSelect_Mode);
        menuSetMode->addAction(actionAssign_IDs);
        mainToolBar->addAction(actionMove_and_Add_Mode);
        mainToolBar->addAction(actionSelect_Mode);
        mainToolBar->addAction(actionAssign_IDs);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSelect_Mode->setText(QApplication::translate("MainWindow", "Select", 0));
        actionMove_and_Add_Mode->setText(QApplication::translate("MainWindow", "Move and Add", 0));
        actionAssign_IDs->setText(QApplication::translate("MainWindow", "Assign IDs", 0));
#ifndef QT_NO_TOOLTIP
        actionAssign_IDs->setToolTip(QApplication::translate("MainWindow", "Assign IDs", 0));
#endif // QT_NO_TOOLTIP
        resetGroupsButton->setText(QApplication::translate("MainWindow", "Reset All Groups", 0));
        displayText->setText(QString());
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        selectRangeButton->setText(QApplication::translate("MainWindow", "Select Inputted Range", 0));
        resetID->setText(QApplication::translate("MainWindow", "Reset IDs", 0));
        deleteSelectedButton->setText(QApplication::translate("MainWindow", "Delete Selected", 0));
        ledNumEdit->setText(QString());
        upArrow->setText(QApplication::translate("MainWindow", "...", 0));
        downArrow->setText(QApplication::translate("MainWindow", "...", 0));
        addFive->setText(QApplication::translate("MainWindow", "Add 5", 0));
        deleteFive->setText(QApplication::translate("MainWindow", "Delete 5", 0));
        clearLEDs->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        addBehaviorButton->setText(QApplication::translate("MainWindow", "Add Behavior", 0));
        selectAllButton->setText(QApplication::translate("MainWindow", "Select All LEDs", 0));
        displayWindowButton->setText(QApplication::translate("MainWindow", "Open Display Window", 0));
        menuSetMode->setTitle(QApplication::translate("MainWindow", "Set Mode", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
