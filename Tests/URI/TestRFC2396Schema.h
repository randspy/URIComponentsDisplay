#ifndef TESTRFC2396SCHEMA_H
#define TESTRFC2396SCHEMA_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396Schema : public QObject
{
    Q_OBJECT

public:
    TestRFC2396Schema();

private slots:
    void schemaMatch();
};

DECLARE_TEST(TestRFC2396Schema)

}
#endif // TESTRFC2396SCHEMA_H
