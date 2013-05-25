#ifndef TESTRFC2396AUTHORITY_H
#define TESTRFC2396AUTHORITY_H

#include "../AutoTest.h"

#include <boost/shared_ptr.hpp>
#include "URILinkParser/URI/URIHandler.h"

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
    void subcomponents();

private:
    boost::shared_ptr<URI::URIHandler> createSubComponents();
};

DECLARE_TEST(TestRFC2396Authority)

}
#endif // TESTRFC2396AUTHORITY_H
