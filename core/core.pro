#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = core
TEMPLATE = lib
DESTDIR = $$OUT_PWD/../lib
LIBS += -L/usr/lib/nvidia-340-updates -L$$DESTDIR -lshapes
INCLUDEPATH += . ..

SOURCES += observer.cpp \
    subject.cpp \
    data.cpp \
    page.cpp \
    page_manager.cpp \
    cord_convertor.cpp

HEADERS  += observer.h \
    subject.h \
    data.h \
    page.h \
    page_manager.h \
    cord_convertor.h
