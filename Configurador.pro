#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T22:54:09
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Configurador
TEMPLATE = app


SOURCES += main.cpp\
        configwindow.cpp \
    manipuladorxml.cpp

HEADERS  += configwindow.h \
    manipuladorxml.h

FORMS    += configwindow.ui

RESOURCES += \
    resources.qrc
