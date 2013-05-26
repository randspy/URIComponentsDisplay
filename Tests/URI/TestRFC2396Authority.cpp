#include "TestRFC2396Authority.h"

#include "URILinkParser/URI/RFC2396Authority.h"
#include "URILinkParser/URI/RFC2396UserInfo.h"
#include "URILinkParser/URI/RFC2396Host.h"
#include "URILinkParser/URI/RFC2396Port.h"

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
    DataTypes::Component component = tree->getChild(0).getValue();

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "authority");
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.edu");
    QCOMPARE(component.isValid(), true);

    handler.parse("//www.ics.uci.edu#sd", tree);
    component = tree->getChild(1).getValue();
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.edu");

    handler.parse("//www.ics.uci.edu?sd", tree);
    component = tree->getChild(1).getValue();
    QCOMPARE(component.getValue().c_str(), "www.ics.uci.edu");

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

void TestRFC2396Authority::subcomponents()
{
    URI::RFC2396Authority handler(createSubComponents());

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("//john.doe@host.com:8080", tree);
    DataTypes::Tree<DataTypes::Component>& child = tree->getChild(0);
    DataTypes::Component component = child.getValue();

    QCOMPARE(child.getTagName().c_str(), "authority");
    QCOMPARE(component.getValue().c_str(), "john.doe@host.com:8080");

    component = child.getChild(0).getValue();
    QCOMPARE(child.getChild(0).getTagName().c_str(), "user information");
    QCOMPARE(component.getValue().c_str(), "john.doe");

    component = child.getChild(1).getValue();
    QCOMPARE(child.getChild(1).getTagName().c_str(), "host");
    QCOMPARE(component.getValue().c_str(), "host.com");

    component = child.getChild(2).getValue();
    QCOMPARE(child.getChild(2).getTagName().c_str(), "port");
    QCOMPARE(component.getValue().c_str(), "8080");

    delete tree;
}

boost::shared_ptr<URI::URIHandler> TestRFC2396Authority::createSubComponents()
{
    boost::shared_ptr<URI::URIHandler> userInfo =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396UserInfo());

    userInfo->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Host()));
    userInfo->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Port()));

    return userInfo;
}

}
