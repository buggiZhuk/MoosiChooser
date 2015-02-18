#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T23:40:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoosiChooser
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    gstcallbacks.cpp \
    UI/filelist.cpp \
    Player/playercontroller.cpp \
    Player/player.cpp \
    Player/contenttypdiscoverer.cpp \
    Helpers/classidentifier.cpp

HEADERS  += mainwindow.h \
    gstcallbacks.h \
    UI/filelist.h \
    Player/playercontroller.h \
    Player/datatypes.h \
    Player/player.h \
    Player/contenttypdiscoverer.h \
    Helpers/classidentifier.h

FORMS    += mainwindow.ui

CONFIG += c++11

unix: CONFIG += link_pkgconfig

unix: PKGCONFIG += gstreamer-0.10
unix: PKGCONFIG += gstreamer-plugins-base-0.10 \
                   gstreamer-pbutils-0.10

