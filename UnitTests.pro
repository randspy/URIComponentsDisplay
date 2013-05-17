#-------------------------------------------------
#
# Project created by QtCreator 2013-05-11T10:31:20
#
#-------------------------------------------------

QT += core
QT += testlib
QT += gui declarative

TARGET = UnitTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Tests/URI/TestRfc2396Parser.cpp \
    URILinkParser/URI/RFC2396URIStandardParser.cpp \
    URILinkParser/URI/MatchedSubStringRetreiver.cpp \
    Tests/URI/TestMatchedSubStringRetreiver.cpp

HEADERS += Tests/AutoTest.h \
    Tests/URI/TestRfc2396Parser.h \
    URILinkParser/URI/RFC2396URIStandardParser.h \
    URILinkParser/URI/URIComponents.h \
    URILinkParser/URI/MatchedSubStringRetreiver.h \
    Tests/URI/TestMatchedSubStringRetreiver.h
    URILinkParser/URI/URIParser.h

INCLUDEPATH += ./usr/include/boost/
LIBS += -L/usr/lib/ -lboost_regex
