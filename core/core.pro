#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = core
TEMPLATE = lib
VPATH += core
LIBS += -L/usr/lib/nvidia-331-updates

SOURCES += observer.cpp \
    subject.cpp \
    data.cpp \
    page.cpp \
    data_manager.cpp \
    page_manager.cpp 

HEADERS  += \
    observer.h \
    subject.h \
    data.h \
    page.h \
    data_manager.h \
    page_manager.h \

FORMS    +=
