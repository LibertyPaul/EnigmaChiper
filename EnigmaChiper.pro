TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    rotor.cpp \
    rotorfactory.cpp \
    rotorparser.cpp \
    reflector.cpp \
    reflectorfactory.cpp \
    parser.cpp \
    enigmamachine.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rotor.hpp \
    rotorfactory.hpp \
    rotorparser.hpp \
    reflector.hpp \
    reflectorfactory.hpp \
    parser.hpp \
    enigmamachine.hpp

