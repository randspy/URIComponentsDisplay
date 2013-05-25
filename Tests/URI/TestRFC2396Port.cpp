#include "TestRFC2396Port.h"

#include "URILinkParser/URI/RFC2396Port.h"

namespace UnitTest
{

TestRFC2396Port::TestRFC2396Port()
{
}

void TestRFC2396Port::portMatch()
{
    URI::RFC2396Port handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse(":8008", tree);
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "port");
    QCOMPARE(component.getValue().c_str(), "8008");
    QCOMPARE(component.isValid(), true);

    delete tree;
}

}
