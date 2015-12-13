#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cmd
TEMPLATE = lib
LIBS += -L/usr/lib/nvidia-340-updates
DESTDIR = $$OUT_PWD/../lib
INCLUDEPATH += . ..

SOURCES += command_service.cpp \
    command_panel.cpp \
    command_parser.cpp \
    command_editor.cpp

HEADERS += command_service.h \
    command_panel.h \
    command_parser.h \
    command_editor.h
