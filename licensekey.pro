#
#       This file is part of licensekey project
#	name of file: licensekey.pro
#
#	Copyright 2014 2015 Filipe Marques <eagle.software3@gmail.com>
#
#	This program is free software; you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation; either version 3 of the License, or
#	any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You received a copy of the GNU General Public License
#	along with this program in License folder; if not, write to the Free Software
#	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#	MA 02110-1301, USA.
#

win32 {
    QT -= core gui
    CONFIG -= qt gui
    # -std=c++11
    CONFIG += c++11
    TARGET = licensekey
    TEMPLATE = lib

    # for shared lib - comment this
    CONFIG += staticlib

    VERSION = 1.0.0
}


unix {
    QT -= core gui
    CONFIG -= qt gui
    CONFIG -= app_bundle
    TARGET = licensekey
    TEMPLATE = lib
    # -std=c++11
    CONFIG += c++11

    #CONFIG += staticlib
    CONFIG += shared

    VERSION = 1.0.0

    DESTDIR = bin

    OBJECTS_DIR = obj
}

DEFINES += LICENSEKEY_LIBRARY

HEADERS += \
    LicenseKey/licensekey.hpp \
    LicenseKey/LicenseKey/hashkey.hpp \
    LicenseKey/LicenseKey/inoutkey.hpp \
    LicenseKey/LicenseKey/listcomparekeys.hpp \

SOURCES += \
    source/hashkey.cpp \
    source/inoutkey.cpp \
    source/listcomparekeys.cpp \

unix {
    target.path = /usr/lib
    target.files = licensekey/bin/*
    target.files = LicenseKey/*
    INSTALLS += target
}
