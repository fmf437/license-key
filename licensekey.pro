CONFIG -= qt
TARGET = licensekey
TEMPLATE = lib

#CONFIG += staticlib
CONFIG += shared

VERSION = 1.0.0

DESTDIR = licensekey/bin

DEFINES += LICENSEKEY_LIBRARY

HEADERS += \
    include/comparekeys.hpp \
    include/hashkey.hpp \
    include/inputkey.hpp \
    include/licensekey.hpp \
    include/listkeys.hpp \
    include/outputkey.hpp \
    include/timekey.hpp

SOURCES += \
    source/comparekeys.cpp \
    source/hashkey.cpp \
    source/inputkey.cpp \
    source/listkeys.cpp \
    source/outputkey.cpp \
    source/timekey.cpp
