TEMPLATE = subdirs

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt
QT += core gui multimedia
QT += widgets

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = app tests

CONFIG += ordered

