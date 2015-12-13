#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = painter
TEMPLATE = app
DESTDIR = $$OUT_PWD/../bin
REL_PATH= $$OUT_PWD/../lib
LIBS += -L/usr/lib/nvidia-340-updates -L$$REL_PATH -lshapes -lcore -lcommands -lcmd
INCLUDEPATH += . ..

SOURCES += Painter.cpp \
        page_tab.cpp \
        main.cpp

HEADERS  += Painter.h \
        page_tab.h

