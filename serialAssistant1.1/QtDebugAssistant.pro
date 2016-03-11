#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T10:42:46
#
#-------------------------------------------------

QT       += core gui

QT       += widgets

QT       +=serialport
QT       +=network

TARGET = QtDebugAssistant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutDialog.cpp

HEADERS  += mainwindow.h \
    aboutDialog.h

FORMS    += mainwindow.ui \
    aboutDialog.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    FBT.png
