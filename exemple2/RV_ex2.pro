#-------------------------------------------------
# Cours de Réalité Virtuelle
# leo.donati@univ-cotedazur.fr
#
# EPU 2018-19
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RV_ex2
TEMPLATE = app

SOURCES += main.cpp\
        widgetopengl.cpp

HEADERS  += widgetopengl.h

windows:LIBS += -lopengl32
