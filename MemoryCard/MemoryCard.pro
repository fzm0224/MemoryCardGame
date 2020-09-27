#-------------------------------------------------
#
# Project created by QtCreator 2018-05-27T19:26:53
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MemoryCard
TEMPLATE = app


SOURCES += main.cpp\
        startui.cpp \
    primary.cpp \
    middle.cpp \
    premium.cpp \
    choosegrade.cpp \
    about.cpp \
    help.cpp \
    gameover.cpp

HEADERS  += startui.h \
    primary.h \
    middle.h \
    premium.h \
    choosegrade.h \
    about.h \
    help.h \
    gameover.h

RESOURCES += \
    image.qrc

CONFIG += c++11

DISTFILES += \
    icon.rc

RC_FILE=icon.rc
