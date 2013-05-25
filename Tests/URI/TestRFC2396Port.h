#ifndef TESTRFC2396PORT_H
#define TESTRFC2396PORT_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Port : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Port();

private slots:
    void portMatch();
};

DECLARE_TEST(TestRFC2396Port)

}

#endif // TESTRFC2396PORT_H
