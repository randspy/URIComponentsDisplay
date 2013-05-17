#ifndef TESTRFC2396PARSER_H
#define TESTRFC2396PARSER_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestRFC2396URIStandardParser : public QObject
{
    Q_OBJECT

public:
    TestRFC2396URIStandardParser();

private slots:

    void missingFragmentComponent();
    void missingQueryComponent();
    void missingSchemaComponent();
    void schemaComponentIsCorupted();
    void urnSchema();
};


DECLARE_TEST(TestRFC2396URIStandardParser)

}

#endif // TESTRFC2396PARSER_H
