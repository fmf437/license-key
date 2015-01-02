TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt gui
CONFIG += c++11

SOURCES += main.cpp

#----------------------------------------------------------------------------------------------------------------------------------------------------
# debug mode shared library
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../debug/bin/release/ -llicensekey
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../debug/bin/debug/ -llicensekey
#else:unix: LIBS += -L$$PWD/../../debug/bin/ -llicensekey

#INCLUDEPATH += $$PWD/../../LicenseKey
#DEPENDPATH += $$PWD/../../LicenseKey

#----------------------------------------------------------------------------------------------------------------------------------------------------
# debug mode static library
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../debug/bin/release/ -llicensekey
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../debug/bin/debug/ -llicensekey
#else:unix: LIBS += -L$$PWD/../../debug/bin/ -llicensekey

#INCLUDEPATH += $$PWD/../../LicenseKey
#DEPENDPATH += $$PWD/../../LicenseKey

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../debug/bin/release/liblicensekey.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../debug/bin/debug/liblicensekey.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../debug/bin/release/licensekey.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../debug/bin/debug/licensekey.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../../debug/bin/liblicensekey.a

#----------------------------------------------------------------------------------------------------------------------------------------------------
# release mode shared library
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../release/bin/release/ -llicensekey
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../release/bin/debug/ -llicensekey
#else:unix: LIBS += -L$$PWD/../../release/bin/ -llicensekey
#
#INCLUDEPATH += $$PWD/../../LicenseKey
#DEPENDPATH += $$PWD/../../LicenseKey

#----------------------------------------------------------------------------------------------------------------------------------------------------
# release mode static library
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../release/bin/release/ -llicensekey
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../release/bin/debug/ -llicensekey
#else:unix: LIBS += -L$$PWD/../../release/bin/ -llicensekey

#INCLUDEPATH += $$PWD/../../LicenseKey
#DEPENDPATH += $$PWD/../../LicenseKey

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../release/bin/release/liblicensekey.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../release/bin/debug/liblicensekey.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../release/bin/release/licensekey.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../release/bin/debug/licensekey.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../../release/bin/liblicensekey.a
