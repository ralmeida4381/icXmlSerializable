#-------------------------------------------------
#
# Project created by QtCreator 2011-09-26T17:23:17
#
#-------------------------------------------------

QT       += core xml
QT       -= gui

TARGET = icXmlSerializable
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    icxmlserializable.cpp

HEADERS += \
    icxmlserializable.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}




