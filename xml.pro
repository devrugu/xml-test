QT -= gui
QT += xml concurrent

CONFIG += c++17 console
CONFIG -= app_bundle

LIBS += -L/opt/test/matio -lmatio
INCLUDEPATH += /opt/test/include

INCLUDEPATH += /opt/test/UtilitiesLibrary/src/ConfigurationParser/xml/headers


# Configuration specific to debug build
CONFIG(debug, debug|release) {
    DESTDIR = $$_PRO_FILE_PWD_/bin/debug
    LIBS += -L"/opt/test/UtilitiesLibrary/lib/debug" \
            -lutilitiesd
    TARGET = xmld
    QMAKE_CXXFLAGS_DEBUG += -O0 -g
}

# Configuration specific to release build
CONFIG(release, debug|release) {
    DESTDIR = $$_PRO_FILE_PWD_/bin/release
    LIBS += -L"/opt/test/UtilitiesLibrary/lib/release" \
            -lutilities
    TARGET = xml
    QMAKE_CXXFLAGS_RELEASE -= -O2
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
