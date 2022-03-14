#-------------------------------------------------
#
# Project created by QtCreator 2020-12-12T11:05:28
#
#-------------------------------------------------

QT       += core gui
QT       += gui
QT       += widgets
QT       += serialport
QT       += xml

TARGET = MainFunction
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    information.cpp \
    seqdesign.cpp \
    ratedesign.cpp \
    usbdesign.cpp \
    gpibdesign.cpp \
    scdesign.cpp \
    rename.cpp \
    landesign.cpp

HEADERS += \
        mainwindow.h \
    information.h \
    seqdesign.h \
    ratedesign.h \
    usbdesign.h \
    gpibdesign.h \
    scdesign.h \
    rename.h \
    landesign.h

FORMS += \
        mainwindow.ui \
    information.ui \
    seqdesign.ui \
    ratedesign.ui \
    usbdesign.ui \
    gpibdesign.ui \
    scdesign.ui \
    rename.ui \
    landesign.ui

RESOURCES += \
    image.qrc

LIBS += -lD:\information\dllfile\ClassLibrary3
LIBS += -lD:\information\dllfile\ClassLibrary4

DISTFILES += \
    pic.rc

RC_FILE += pic.rc
