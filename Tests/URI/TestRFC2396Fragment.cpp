#include "TestRFC2396Fragment.h"

#include "URILinkParser/URI/RFC2396Fragment.h"

namespace UnitTest
{

TestRFC2396Fragment::TestRFC2396Fragment()
{
}

void TestRFC2396Fragment::fragmentMatch()
{
    URI::RFC2396Fragment handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("#asd", tree);
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "fragment");
    QCOMPARE(component.getValue().c_str(), "asd");
    QCOMPARE(component.isValid(), true);

    delete tree;
}

void TestRFC2396Fragment::fragmentDoNotMatch()
{
    URI::RFC2396Fragment handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("asd", tree);

    QVERIFY_THROW(tree->getChild(0), std::out_of_range);

    delete tree;
}

}
