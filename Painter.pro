#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Painter
TEMPLATE = subdir
LIBS += -L/usr/lib/nvidia-331-updates
INCLUDEPATH += $$PWD
SUBDIRS = cmd \
          commands \
          core \
          painter \
          shapes

include($$PWD/cmd/cmd.pro)
include($$PWD/commands/commands.pro)
include($$PWD/core/core.pro)
include($$PWD/painter/painter.pro)
include($$PWD/shapes/shapes.pro)
