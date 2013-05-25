#ifndef TESTRFC2396AUTHORITY_H
#define TESTRFC2396AUTHORITY_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Authority : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Authority();

private slots:
    void authorityMatch();
    void authorityDoNotMatch();
};

DECLARE_TEST(TestRFC2396Authority)

}
#endif // TESTRFC2396AUTHORITY_H
