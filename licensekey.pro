TARGET = licensekey
TEMPLATE = lib
CONFIG = dll
VERSION = 1.0.0

DEFINES += LICENSEKEY_LIBRARY

CONFIG -= qt

HEADERS += \
    listkeys.hpp \
    hashkey.hpp \
    inputkey.hpp \
    outputkey.hpp \
    comparekeys.hpp \
    timekey.hpp \
    licensekey.hpp

SOURCES += \
    listkeys.cpp \
    hashkey.cpp \
    inputkey.cpp \
    outputkey.cpp \
    comparekeys.cpp \
    timekey.cpp
