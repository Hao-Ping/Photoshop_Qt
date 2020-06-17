#-------------------------------------------------
#
# Project created by QtCreator 2020-01-28T18:36:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = photoshop
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

CONFIG += c++11

SOURCES += \
        brightness.cpp \
        filter.cpp \
        hue.cpp \
        main.cpp \
        mainwindow.cpp \
        rgb.cpp \
        saturation.cpp

HEADERS += \
        brightness.h \
        filter.h \
        hue.h \
        mainwindow.h \
        rgb.h \
        saturation.h

FORMS += \
        brightness.ui \
        filter.ui \
        hue.ui \
        mainwindow.ui \
        rgb.ui \
        saturation.ui
#for opencv
INCLUDEPATH += /usr/local/opt/opencv@3/include

LIBS += -L/usr/local/opt/opencv@3/lib\
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_imgcodecs \
        -lopencv_highgui \
        -lopencv_features2d \
        -lopencv_video \
        -lopencv_videoio

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR += ../bin
