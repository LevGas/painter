#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = commands
TEMPLATE = lib
VPATH += commands
LIBS += -L/usr/lib/nvidia-331-updates

SOURCES += command_base.cpp \
    create_command_base.cpp \
    create_rect_command.cpp \
    create_circle_command.cpp \
    clear_command.cpp \
    close_command.cpp \
    exit_command.cpp \

HEADERS += \
    command_base.h \
    create_command_base.h \
    create_rect_command.h \
    create_circle_command.h \
    clear_command.h \
    close_command.h \
    exit_command.h 

FORMS    +=
