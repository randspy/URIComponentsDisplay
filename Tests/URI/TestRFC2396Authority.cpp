#include "TestRFC2396Authority.h"

#include "URILinkParser/URI/RFC2396Authority.h"

namespace UnitTest
{

TestRFC2396Authority::TestRFC2396Authority()
{

}

void TestRFC2396Authority::authorityMatch()
{
    URI::RFC2396Authority handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("//www.ics.uci.edu", tree);
    DataTypes::Component aSchema = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName(), std::string("authority"));
//    QCOMPARE(aSchema.getValue(), std::string("www.ics.uci.edu"));
//    QCOMPARE(aSchema.isValid(), true);
}

}
