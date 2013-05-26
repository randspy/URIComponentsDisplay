#include "TestRFC2396Path.h"

#include "URILinkParser/URI/RFC2396Path.h"

namespace UnitTest
{

TestRFC2396Path::TestRFC2396Path()
{
}

void TestRFC2396Path::pathMatch()
{
    URI::RFC2396Path handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("/www.ics.uci.edu", tree);
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "path");
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.edu");
    QCOMPARE(component.isValid(), true);

    handler.parse("www.ics.uci.com#sd", tree);
    component = tree->getChild(1).getValue();
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.com");

    handler.parse("www.ics.uci.com/23/se?sd", tree);
    component = tree->getChild(2).getValue();
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.com/23/se");

    handler.parse("/www.ics.uci.com/23/ee#sd?23", tree);
    component = tree->getChild(3).getValue();
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.com/23/ee");

    delete tree;
}

void TestRFC2396Path::pathDoNotMatch()
{
    URI::RFC2396Path handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("?sdfs=3", tree);

    QVERIFY_THROW(tree->getChild(0), std::out_of_range);

    delete tree;
}

}
