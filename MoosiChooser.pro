#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T23:40:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoosiChooser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    player.cpp \
    gststreemdiscoverer.cpp \
    test.cpp \
    gstcallbacks.cpp

HEADERS  += mainwindow.h \
    controller.h \
    player.h \
    gststreemdiscoverer.h \
    test.h \
    gstcallbacks.h

FORMS    += mainwindow.ui

CONFIG += c++11

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += gstreamer-1.0

