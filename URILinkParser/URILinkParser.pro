#-------------------------------------------------
#
# Project created by QtCreator 2013-05-11T12:31:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = URILinkParser
TEMPLATE = app

HEADERS += Tests/AutoTest.h \
    Tests/TestRfc2396Parser.h \
    URI/RFC2396URIStandardParser.h \
    URI/URIComponents.h \
    URI/MatchedSubStringRetreiver.h \
    URI/URIParser.h


SOURCES += main.cpp\
        MainWindow.cpp\
        URI/RFC2396URIStandardParser.cpp \
        URI/MatchedSubStringRetreiver.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui


INCLUDEPATH += ./usr/include/boost/
LIBS += -L/usr/lib/ -lboost_regex

