#ifndef TESTRFC2396HOST_H
#define TESTRFC2396HOST_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Host : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Host();

private slots:
    void hostMatch();
    void hostWithSquareBrackets();
};

DECLARE_TEST(TestRFC2396Host)

}

#endif // TESTRFC2396HOST_H
