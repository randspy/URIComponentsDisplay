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
    Tests/URI/TestMatchedSubStringRetreiver.cpp \
    Tests/DataTypes/TestTree.cpp \
    URILinkParser/URI/RFC2396Schema.cpp \
    Tests/URI/TestRFC2396Schema.cpp \
    URILinkParser/URI/RFC2396Authority.cpp \
    Tests/URI/TestRFC2396Authority.cpp \
    URILinkParser/URI/RFC2396Handler.cpp \
    URILinkParser/URI/RFC2396Path.cpp \
    Tests/URI/TestRFC2396Path.cpp \
    URILinkParser/URI/RFC2396Query.cpp \
    Tests/URI/TestRFC2396Query.cpp \
    URILinkParser/URI/RFC2396Fragment.cpp \
    Tests/URI/TestRFC2396Fragment.cpp \
    URILinkParser/URI/RFC2396UserInfo.cpp \
    Tests/URI/TestRFC2396UserInfo.cpp \
    URILinkParser/URI/RFC2396Host.cpp \
    Tests/URI/TestRFC2396Host.cpp \
    URILinkParser/URI/RFC2396Port.cpp \
    Tests/URI/TestRFC2396Port.cpp \
    URILinkParser/URI/RFC2396HandlerWithSubComponents.cpp \
    Tests/URI/TestRFC2396URIStandardParser.cpp \
    URILinkParser/URI/Regex.cpp

HEADERS += Tests/AutoTest.h \
    URILinkParser/DataTypes/Component.h \
    URILinkParser/DataTypes/Tree.h \
    Tests/DataTypes/TestTree.h \
    URILinkParser/URI/URIHandler.h \
    URILinkParser/URI/RFC2396Schema.h \
    Tests/URI/TestRFC2396Schema.h \
    URILinkParser/URI/RFC2396Authority.h \
    Tests/URI/TestRFC2396Authority.h \
    URILinkParser/URI/RFC2396Handler.h \
    URILinkParser/URI/RFC2396Path.h \
    Tests/URI/TestRFC2396Path.h \
    URILinkParser/URI/RFC2396Query.h \
    Tests/URI/TestRFC2396Query.h \
    URILinkParser/URI/RFC2396Fragment.h \
    Tests/URI/TestRFC2396Fragment.h \
    URILinkParser/URI/RFC2396UserInfo.h \
    Tests/URI/TestRFC2396UserInfo.h \
    URILinkParser/URI/RFC2396Host.h \
    Tests/URI/TestRFC2396Host.h \
    URILinkParser/URI/RFC2396Port.h \
    Tests/URI/TestRFC2396Port.h \
    URILinkParser/URI/RFC2396HandlerWithSubComponents.h \
    Tests/URI/TestRFC2396URIStandardParser.h \
    URILinkParser/URI/Regex.h \
    Tests/URI/TestRegex.h

INCLUDEPATH += ./usr/include/boost/
LIBS += -L/usr/lib/ -lboost_regex
