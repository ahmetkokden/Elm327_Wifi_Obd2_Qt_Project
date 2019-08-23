#-------------------------------------------------
#
# Project created by QtCreator 2019-08-21T17:33:32
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Elm327Obd
TEMPLATE = app

win32:RC_ICONS += $$PWD\icons\app_ico.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        networkmanager.cpp \
        obdscan.cpp

HEADERS += \
        mainwindow.h \
        networkmanager.h \
        obdscan.h \
        pid.h

FORMS += \
        mainwindow.ui \
        obdscan.ui