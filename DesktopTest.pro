#-------------------------------------------------
#
# Project created by QtCreator 2020-10-22T08:41:58
#
#-------------------------------------------------

QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DesktopTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#-------------------------------------------------------------------------------
# Make options
#-------------------------------------------------------------------------------

UI_DIR = uic
MOC_DIR = moc
RCC_DIR = qrc
OBJECTS_DIR = obj

CONFIG += c++11

#-------------------------------------------------------------------------------
# Deploy options
#-------------------------------------------------------------------------------


linux:!android {
    target.path = $$(QMAKE_DESTIDIR)/usr/bin

    INSTALLS += target
}

#-------------------------------------------------------------------------------
# Import source code
#-------------------------------------------------------------------------------

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    sensor.cpp \
    file.cpp \
    keyboard.cpp

HEADERS += \
        mainwindow.h \
    dialog.h \
    sensor.h \
    main.h \
    file.h \
    keyboard.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    keyboard.ui

DISTFILES +=


DESTDIR = $$(QMAKE_DESTIDIR)