QT += core widgets

CONFIG += c++11

TARGET = proyecto_programacion_Medranda_Armas_Gonzales
TEMPLATE = app

SOURCES += main.cpp \
           crud.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h \
           Cancion.h \
           cancion.h \
           crud.h

FORMS += mainwindow.ui