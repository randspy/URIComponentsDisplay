#include "TestRFC2396Host.h"

#include "URILinkParser/URI/RFC2396Host.h"

namespace UnitTest
{

TestRFC2396Host::TestRFC2396Host()
{
}


void TestRFC2396Host::hostMatch()
{
    URI::RFC2396Host handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("host.com:8008", tree);
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "host");
    QCOMPARE(component.getValue().c_str(), "host.com");
    QCOMPARE(component.isValid(), true);

    handler.parse("host.fr", tree);
    component = tree->getChild(1).getValue();

    QCOMPARE(component.getValue().c_str(), "host.fr");
}

}
