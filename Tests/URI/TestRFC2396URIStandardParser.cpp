#include "TestRFC2396URIStandardParser.h"

#include "URILinkParser/URI/RFC2396Authority.h"
#include "URILinkParser/URI/RFC2396Fragment.h"
#include "URILinkParser/URI/RFC2396Host.h"
#include "URILinkParser/URI/RFC2396Path.h"
#include "URILinkParser/URI/RFC2396Port.h"
#include "URILinkParser/URI/RFC2396Query.h"
#include "URILinkParser/URI/RFC2396Schema.h"
#include "URILinkParser/URI/RFC2396UserInfo.h"

namespace UnitTest
{

TestRFC2396URIStandardParser::TestRFC2396URIStandardParser()
{
}

void TestRFC2396URIStandardParser::allComponentsPresent()
{
    boost::shared_ptr<URI::URIHandler> component = createAllComponents();

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    component->parse("foo://username:password@example.com:8042/over/there/index.dtb?type=animal&name=narwhal#nose", tree);

    QCOMPARE(tree->getChild(0).getTagName().c_str(), "schema");
    QCOMPARE(tree->getChild(0).getValue().getValue().c_str(), "foo");

    QCOMPARE(tree->getChild(1).getTagName().c_str(), "authority");
    QCOMPARE(tree->getChild(1).getValue().getValue().c_str(), "username:password@example.com:8042");

    DataTypes::Tree<DataTypes::Component>& child = tree->getChild(1);
    QCOMPARE(child.getChild(0).getTagName().c_str(), "user information");
    QCOMPARE(child.getChild(0).getValue().getValue().c_str(), "username:password");

    QCOMPARE(child.getChild(1).getTagName().c_str(), "host");
    QCOMPARE(child.getChild(1).getValue().getValue().c_str(), "example.com");

    QCOMPARE(child.getChild(2).getTagName().c_str(), "port");
    QCOMPARE(child.getChild(2).getValue().getValue().c_str(), "8042");

    QCOMPARE(tree->getChild(2).getTagName().c_str(), "path");
    QCOMPARE(tree->getChild(2).getValue().getValue().c_str(), "over/there/index.dtb");

    QVERIFY_THROW(tree->getChild(2).getChild(0), std::out_of_range);

    QCOMPARE(tree->getChild(3).getTagName().c_str(), "query");
    QCOMPARE(tree->getChild(3).getValue().getValue().c_str(), "type=animal&name=narwhal");

    QCOMPARE(tree->getChild(4).getTagName().c_str(), "fragment");
    QCOMPARE(tree->getChild(4).getValue().getValue().c_str(), "nose");

    delete tree;
}

boost::shared_ptr<URI::URIHandler> TestRFC2396URIStandardParser::createAllComponents()
{
    boost::shared_ptr<URI::URIHandler> userInfo =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396UserInfo);

    userInfo->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Host));
    userInfo->setNext( boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Port));

    boost::shared_ptr<URI::URIHandler> schema =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Schema);

    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Authority(userInfo)));
    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Path()));
    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Query));
    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Fragment));

    return schema;
}

}


