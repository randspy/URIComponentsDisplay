#include "TestRFC2396Query.h"

#include "URILinkParser/URI/RFC2396Query.h"

namespace UnitTest
{

TestRFC2396Query::TestRFC2396Query()
{
}

void TestRFC2396Query::queryMatch()
{
    URI::RFC2396Query handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("?asd", tree);
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "query");
    QCOMPARE(component.getValue().c_str(), "asd");
    QCOMPARE(component.isValid(), true);

    handler.parse("?ddd#", tree);
    component = tree->getChild(1).getValue();
    QCOMPARE(component.getValue().c_str(), "ddd");

    delete tree;
}

}
