TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    rotor.cpp \
    factory.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rotor.hpp \
    factory.hpp

