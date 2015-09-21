#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cmd
TEMPLATE = lib
VPATH += cmd
LIBS += -L/usr/lib/nvidia-331-updates

SOURCES += command_service.cpp \
    command_panel.cpp \
    command_parser.cpp \
    line_edit.cpp

HEADERS += \
    command_service.h \
    command_panel.h \
    command_parser.h \
    line_edit.h

FORMS    +=
