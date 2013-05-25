#ifndef TESTRFC2396USERINFO_H
#define TESTRFC2396USERINFO_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396UserInfo : public QObject
{
    Q_OBJECT

public:
    TestRFC2396UserInfo();

private slots:
    void userInfoMatch();
    void userInfoDoNotMatch();
};

DECLARE_TEST(TestRFC2396UserInfo)

}

#endif // TESTRFC2396USERINFO_H
