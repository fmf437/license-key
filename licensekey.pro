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

QT -= core gui
CONFIG -= core qt gui
CONFIG += c++11
TARGET = licensekey
TEMPLATE = lib
CONFIG += shared
CONFIG += release
VER_MAJ = 2
VER_MIN = 0
VER_PAT = 0
DESTDIR = bin
OBJECTS_DIR = obj
DEFINES += LICENSEKEY_LIBRARY
HEADERS += LicenseKey/LicenseKey.hpp
SOURCES += LicenseKey/LicenseKey.cpp
QMAKE_CXXFLAGS += -s

#unix: LIBS += -L$$PWD/../../../../usr/lib/ -lbotan-1.11

#INCLUDEPATH += $$PWD/../../../../usr/include/botan-1.11/
#DEPENDPATH += $$PWD/../../../../usr/include/botan-1.11/
