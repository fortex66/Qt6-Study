QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

INCLUDEPATH += $$PWD/../MyUtil
DEPENDPATH  += $$PWD/../MyUtil


LIBS += -L$$PWD/../build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/MyUtil/debug -lMyUtil
