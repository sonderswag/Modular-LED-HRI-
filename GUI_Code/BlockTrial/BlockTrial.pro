#-------------------------------------------------
#
# Project created by QtCreator 2016-06-30T10:18:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlockTrial
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp\
    ledlabel.cpp \
    behaviorwindow.cpp\
    displaywindow.cpp \
    clickabledisplay.cpp \
    Dependencies/NeoPixelCodeConverter.cpp \
    Dependencies/LightParameter.cpp \
    timeline.cpp \
    linewithtime.cpp

HEADERS  += mainwindow.h\
    ledlabel.h \
    behaviorwindow.h\
    displaywindow.h \
    clickabledisplay.h \
    Dependencies/NeoPixelCodeConverter.h \
    Dependencies/LightParameter.h \
    timeline.h \
    linewithtime.h

RESOURCES   = draggableicons.qrc

FORMS    += mainwindow.ui \
    behaviorwindow.ui \
    displaywindow.ui \
    timeline.ui

