#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = painter
TEMPLATE = app
VPATH += painter
LIBS += -L/usr/lib/nvidia-331-updates

SOURCES += main.cpp \
    Painter.cpp \
    page_tab.cpp 

HEADERS  += \
    Painter.h \
    page_tab.h 

FORMS    +=
