#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shapes
TEMPLATE = lib
INCLUDEPATH += . ..
DESTDIR = $$OUT_PWD/../lib
LIBS += -L/usr/lib/nvidia-340-updates


SOURCES += shape_base.cpp \
    rectangle.cpp \
    circle.cpp \  
    square.cpp \
    line.cpp

HEADERS  += shape_base.h \
    rectangle.h \
    circle.h \  
    square.h \
    line.h
    
