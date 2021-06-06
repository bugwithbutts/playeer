include(gtest_dependency.pri)
TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt
QT += core gui multimedia
QT += widgets
QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


INCLUDEPATH += ../app

SOURCES += main.cpp \
    ../app/songlist.cpp

HEADERS += \
    ../app/songlist.h \
    songtest.h

DISTFILES += \
    tst/1.mp3 \
    tst/2.mp3 \
    tst/3.mp3 \
    tst2
