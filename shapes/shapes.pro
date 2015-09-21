#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shapes
TEMPLATE = lib
VPATH += shapes
LIBS += -L/usr/lib/nvidia-331-updates

SOURCES += shape_base.cpp \
    rectangle.cpp \
    circle.cpp 

HEADERS  += \
    shape_base.h \
    rectangle.h \
    circle.h 
    
FORMS    +=
