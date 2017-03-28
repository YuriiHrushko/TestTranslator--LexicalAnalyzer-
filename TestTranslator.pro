QT += core
QT -= gui

TARGET = TestTranslator
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    position.cpp \
    textserializer.cpp \
    parser.cpp

HEADERS += \
    position.h \
    textserializer.h \
    parser.h

