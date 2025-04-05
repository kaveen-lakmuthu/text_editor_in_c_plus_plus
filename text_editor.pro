QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEditor
TEMPLATE = app

SOURCES += main.cpp \
           editor.cpp

HEADERS += editor.h
