#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T10:48:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dslrControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    context.c

HEADERS  += mainwindow.h \
    samples.h

FORMS    += mainwindow.ui

LIBS += -L/usr/local/lib/ -lgphoto2

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
