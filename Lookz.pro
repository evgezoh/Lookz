#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T23:05:06
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lookz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pictures.cpp \
    processor.cpp \
    startmenu.cpp

HEADERS  += mainwindow.h \
    pictures.h \
    processor.h \
    startmenu.h

FORMS    += mainwindow.ui \
    startmenu.ui

RESOURCES += \
    images.qrc

DISTFILES +=
