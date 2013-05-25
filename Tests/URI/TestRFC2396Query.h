#ifndef TESTRFC2396QUERY_H
#define TESTRFC2396QUERY_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Query : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Query();

private slots:
    void queryMatch();
};

DECLARE_TEST(TestRFC2396Query)

}

#endif // TESTRFC2396QUERY_H
