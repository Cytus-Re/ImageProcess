#-------------------------------------------------
#
# Project created by QtCreator 2021-11-21T16:48:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencv_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    function.cpp

HEADERS  += mainwindow.h \
    function.h

FORMS    += mainwindow.ui

INCLUDEPATH+= /usr/local/opencv3/opencv/include\
              /usr/local/opencv3/opencv/include/opencv \
              /usr/local/opencv3/opencv/include/opencv2 \

LIBS+=  /usr/local/opencv3/opencv/lib/libopencv_highgui.so\
        /usr/local/opencv3/opencv/lib/libopencv_core.so \
        /usr/local/opencv3/opencv/lib/libopencv_imgcodecs.so \
        /usr/local/opencv3/opencv/lib/libopencv_videoio.so \
        /usr/local/opencv3/opencv/lib/libz.so \
        /usr/local/opencv3/opencv/lib/libjpeg.so \
        /usr/local/opencv3/opencv/lib/libpng15.so \
        /usr/local/opencv3/opencv/lib/libopencv_imgproc.so    -Wl,--hash-style=sysv


QMAKE_CXXFLAGS+= -Wl,--hash-style=sysv

