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
    Tests/URI/TestMatchedSubStringRetreiver.cpp \
    Tests/DataTypes/TestTree.cpp \
    URILinkParser/URI/RFC2396Schema.cpp \
    Tests/URI/TestRFC2396Schema.cpp \
    URILinkParser/URI/RFC2396Authority.cpp \
    Tests/URI/TestRFC2396Authority.cpp \
    URILinkParser/URI/RFC2396Handler.cpp

HEADERS += Tests/AutoTest.h \
    Tests/URI/TestRfc2396Parser.h \
    URILinkParser/URI/RFC2396URIStandardParser.h \
    URILinkParser/URI/URIComponents.h \
    URILinkParser/URI/MatchedSubStringRetreiver.h \
    Tests/URI/TestMatchedSubStringRetreiver.h \
    URILinkParser/DataTypes/Component.h \
    URILinkParser/DataTypes/Tree.h \
    Tests/DataTypes/TestTree.h \
    URILinkParser/URI/URIHandler.h \
    URILinkParser/URI/RFC2396Schema.h \
    Tests/URI/TestRFC2396Schema.h \
    URILinkParser/URI/URIParser.h \
    URILinkParser/URI/RFC2396Authority.h \
    Tests/URI/TestRFC2396Authority.h \
    URILinkParser/URI/RFC2396Handler.h

INCLUDEPATH += ./usr/include/boost/
LIBS += -L/usr/lib/ -lboost_regex
