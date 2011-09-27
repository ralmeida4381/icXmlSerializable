#-------------------------------------------------
#
# Project created by QtCreator 2011-09-26T17:33:25
#
#-------------------------------------------------

QT       += core gui xml
TARGET = Demo
TEMPLATE = app
INCLUDEPATH += ../icSerializable
LIBS    += -L../icSerializable
LIBS    += -licXmlSerializable


SOURCES += main.cpp\
        dialog.cpp \
    objecta.cpp \
    test6.cpp \
    test5.cpp \
    test4.cpp \
    test3.cpp \
    test3_child.cpp \
    test2.cpp \
    test1.cpp

HEADERS  += dialog.h \
    objecta.h \
    test6.h \
    test5.h \
    test4.h \
    test3.h \
    test3_child.h \
    test2.h \
    test1.h

FORMS    += dialog.ui




