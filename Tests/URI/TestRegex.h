#ifndef TESTREGEX_H
#define TESTREGEX_H

#include "../AutoTest.h"

namespace UnitTest {

class TestRegex : public QObject
{
     Q_OBJECT

public:
    TestRegex();

private slots:

    void subStringMatch();
    void subStringDoNotMatch();
    void stringMatch();
};


DECLARE_TEST(TestRegex)

}

#endif // TESTREGEX_H
