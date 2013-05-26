#ifndef TESTRFC2396STANDARDPARSER_H
#define TESTRFC2396STANDARDPARSER_H

#include "../AutoTest.h"

#include <boost/shared_ptr.hpp>
#include "URILinkParser/URI/URIHandler.h"

namespace UnitTest
{

class TestRFC2396URIStandardParser : public QObject
{
    Q_OBJECT

public:
    TestRFC2396URIStandardParser();

private slots:

    void allComponentsPresent();

private:
    boost::shared_ptr<URI::URIHandler> createAllComponents();
};


DECLARE_TEST(TestRFC2396URIStandardParser)

}

#endif // TESTRFC2396STANDARDPARSER_H
