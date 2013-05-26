#ifndef TESTRFC2396PATH_H
#define TESTRFC2396PATH_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Path : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Path();

private slots:
    void pathMatch();
    void pathDoNotMatch();
};

DECLARE_TEST(TestRFC2396Path)

}

#endif // TESTRFC2396PATH_H
