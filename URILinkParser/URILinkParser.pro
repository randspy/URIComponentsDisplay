#-------------------------------------------------
#
# Project created by QtCreator 2013-05-11T12:31:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = URILinkParser
TEMPLATE = app

HEADERS += URI/MatchedSubStringRetreiver.h \
    DataTypes/Component.h \
    DataTypes/Tree.h \
    URI/URIHandler.h \
    URI/RFC2396Schema.h \
    URI/URIParser.h \
    URI/RFC2396Authority.h \
    URI/RFC2396Handler.h \
    URI/RFC2396Path.h \
    URI/RFC2396Query.h \
    URI/RFC2396Fragment.h \
    URI/RFC2396UserInfo.h \
    URI/RFC2396Host.h \
    URI/RFC2396Port.h \
    URI/RFC2396HandlerWithSubComponents.h \
    Builder/URIHandlerBuilder.h


SOURCES += main.cpp\
        MainWindow.cpp\
        URI/MatchedSubStringRetreiver.cpp \
        URI/RFC2396Schema.cpp \
        URI/RFC2396Authority.cpp \
        URI/RFC2396Handler.cpp \
        URI/RFC2396Path.cpp \
        URI/RFC2396Query.cpp \
        URI/RFC2396Fragment.cpp \
        URI/RFC2396UserInfo.cpp \
        URI/RFC2396Host.cpp \
        URI/RFC2396Port.cpp \
        URI/RFC2396HandlerWithSubComponents.cpp \
        Builder/URIHandlerBuilder.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui


INCLUDEPATH += ./usr/include/boost/
LIBS += -L/usr/lib/ -lboost_regex

