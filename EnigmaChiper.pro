TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    rotor.cpp \
    factory.cpp \
    rotorfactory.cpp \
    rotorparser.cpp \
    reflector.cpp \
    reflectorfactory.cpp \
    reflectorparser.cpp \
    parser.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rotor.hpp \
    factory.hpp \
    rotorfactory.hpp \
    rotorparser.hpp \
    reflector.hpp \
    reflectorfactory.hpp \
    reflectorparser.hpp \
    parser.hpp

