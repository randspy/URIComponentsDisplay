#ifndef TESTRFC2396FRAGMENT_H
#define TESTRFC2396FRAGMENT_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Fragment : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Fragment();

private slots:
    void fragmentMatch();
    void fragmentDoNotMatch();

};

DECLARE_TEST(TestRFC2396Fragment)

}

#endif // TESTRFC2396FRANGMENT_H
