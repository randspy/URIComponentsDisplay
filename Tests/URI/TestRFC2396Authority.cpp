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

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "authority");
    QCOMPARE(aSchema.getValue().c_str(), "www.ics.uci.edu");
    QCOMPARE(aSchema.isValid(), true);

    handler.parse("//www.ics.uci.edu#sd", tree);
    aSchema = tree->getChild(1).getValue();
    QCOMPARE(aSchema.getValue().c_str(), "www.ics.uci.edu");

    handler.parse("//www.ics.uci.edu?sd", tree);
    aSchema = tree->getChild(1).getValue();
    QCOMPARE(aSchema.getValue().c_str(), "www.ics.uci.edu");

    delete tree;
}

void TestRFC2396Authority::authorityDoNotMatch()
{
    URI::RFC2396Authority handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("www.ics.uci.edu", tree);

    QVERIFY_THROW(tree->getChild(0), std::out_of_range);

    delete tree;
}

}
