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
    bookstore.cpp \
    book.cpp \
    storesection.cpp \
    bookview.cpp

HEADERS  += dialog.h \
    bookstore.h \
    book.h \
    storesection.h \
    bookview.h

FORMS    += dialog.ui \
    bookview.ui

OTHER_FILES += \
    history.txt
































