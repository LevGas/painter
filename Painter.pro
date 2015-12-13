#-------------------------------------------------
#
# Project created by QtCreator 2015-09-05T20:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Painter
TEMPLATE = subdirs

SUBDIRS += shapes \
          core \
          commands \
          cmd \

CONFIG += ordered
SUBDIRS += painter

