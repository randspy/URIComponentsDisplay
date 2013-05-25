#include "TestRFC2396UserInfo.h"

#include "URILinkParser/URI/RFC2396UserInfo.h"

namespace UnitTest
{

TestRFC2396UserInfo::TestRFC2396UserInfo()
{
}

void TestRFC2396UserInfo::userInfoMatch()
{
    URI::RFC2396UserInfo handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("john.doe@host.com:8008", tree);
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "user information");
    QCOMPARE(component.getValue().c_str(), "john.doe");
    QCOMPARE(component.isValid(), true);
}

void TestRFC2396UserInfo::userInfoDoNotMatch()
{
    URI::RFC2396UserInfo handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("//john.doe.com", tree);

    QVERIFY_THROW(tree->getChild(0), std::out_of_range);
}

}
