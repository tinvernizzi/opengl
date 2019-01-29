#-------------------------------------------------
# Cours de Réalité Virtuelle
# leo.donati@univ-cotedazur.fr
#
# EPU 2018-19
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RV_ex0
TEMPLATE = app

SOURCES += main.cpp\
        widgetopengl.cpp

HEADERS  += widgetopengl.h

FORMS    +=


INCLUDEPATH +=

linux:LIBS += -lGLU
windows:LIBS += -lglu32 \
                -lopengl32

