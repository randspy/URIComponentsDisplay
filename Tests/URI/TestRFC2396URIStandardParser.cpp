#include "TestRFC2396URIStandardParser.h"

#include "URILinkParser/URI/RFC2396URIStandardParser.h"
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

void TestRFC2396URIStandardParser::missingFragmentComponent()
{
    URI::RFC2396URIStandardParser uriParser("ldap://[2001:db8::7]/c=GB?objectClass?one");
    URI::URIComponents comp = uriParser.parseURI();

    QCOMPARE(comp.getSchema().c_str(), "ldap");
    QCOMPARE(comp.getAuthority().c_str(), "[2001:db8::7]");
    QCOMPARE(comp.getPath().c_str(), "/c=GB");
    QCOMPARE(comp.getQuery().c_str(), "objectClass?one");
    QCOMPARE(comp.getFragment().c_str(), "");
}

void TestRFC2396URIStandardParser::missingQueryComponent()
{
    URI::RFC2396URIStandardParser uriParser("http://www.ics.uci.edu/pub/ietf/uri/#Related");
    URI::URIComponents comp = uriParser.parseURI();

    QCOMPARE(comp.getSchema().c_str(), "http");
    QCOMPARE(comp.getAuthority().c_str(), "www.ics.uci.edu");
    QCOMPARE(comp.getPath().c_str(), "/pub/ietf/uri/");
    QCOMPARE(comp.getQuery().c_str(), "");
    QCOMPARE(comp.getFragment().c_str(), "Related");
}

void TestRFC2396URIStandardParser::missingSchemaComponent()
{
    URI::RFC2396URIStandardParser uriParser("www.ics.uci.edu/pub/ietf/uri/#Related");
    URI::URIComponents comp = uriParser.parseURI();

    QCOMPARE(comp.getSchema().c_str(), "");
    QCOMPARE(comp.getAuthority().c_str(), "www.ics.uci.edu");
}

void TestRFC2396URIStandardParser::schemaComponentIsCorupted()
{
    URI::RFC2396URIStandardParser uriParser("ht#tp://www.ics.uci.edu/pub/ietf/uri/#Related");
    URI::URIComponents comp = uriParser.parseURI();

    QCOMPARE(comp.getSchema().c_str(), "");
}

void TestRFC2396URIStandardParser::urnSchema()
{
    URI::RFC2396URIStandardParser uriParser("urn:example:animal:ferret:nose");
    URI::URIComponents comp = uriParser.parseURI();

    QCOMPARE(comp.getAuthority().c_str(), "");
}

void TestRFC2396URIStandardParser::schema()
{
    URI::RFC2396URIStandardParser uriParser("http://www.ics.uci.edu/pub/ietf/uri/#Related");
    URI::RFC2396URIStandardParser::Components comp = uriParser.getParsedComponents();
    DataTypes::Component aSchema = comp->getChild(0).getValue();

    QCOMPARE(aSchema.getValue().c_str(), "http");
    QCOMPARE(comp->getChild(0).getTagName().c_str(), "schema");
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

    QCOMPARE(tree->getChild(3).getTagName().c_str(), "query");
    QCOMPARE(tree->getChild(3).getValue().getValue().c_str(), "type=animal&name=narwhal");

    QCOMPARE(tree->getChild(4).getTagName().c_str(), "fragment");
    QCOMPARE(tree->getChild(4).getValue().getValue().c_str(), "nose");

    delete tree;
}

void TestRFC2396URIStandardParser::subComponentsInPath()
{
    boost::shared_ptr<URI::URIHandler> component = createAllComponents();

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    component->parse("foo:fred@example.com?al", tree);

    QCOMPARE(tree->getChild(1).getTagName().c_str(), "path");
    QCOMPARE(tree->getChild(1).getValue().getValue().c_str(), "fred@example.com");

    DataTypes::Tree<DataTypes::Component>& child = tree->getChild(1);
    QCOMPARE(child.getChild(0).getTagName().c_str(), "user information");
    QCOMPARE(child.getChild(0).getValue().getValue().c_str(), "fred");

    QCOMPARE(child.getChild(1).getTagName().c_str(), "host");
    QCOMPARE(child.getChild(1).getValue().getValue().c_str(), "example.com");

    QVERIFY_THROW(child.getChild(2), std::out_of_range);

    delete tree;
}

boost::shared_ptr<URI::URIHandler> TestRFC2396URIStandardParser::createAllComponents()
{
    boost::shared_ptr<URI::URIHandler> userInfo =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396UserInfo);
    boost::shared_ptr<URI::URIHandler> port =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Port);
    boost::shared_ptr<URI::URIHandler> host =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Host);

    host->setNext(port);
    userInfo->setNext(host);

    boost::shared_ptr<URI::URIHandler> schema =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Schema);
    boost::shared_ptr<URI::URIHandler> authority =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Authority(userInfo));
    boost::shared_ptr<URI::URIHandler> fragment =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Fragment);
    boost::shared_ptr<URI::URIHandler> path =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Path(userInfo));
    boost::shared_ptr<URI::URIHandler> query =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Query);

    query->setNext(fragment);
    path->setNext(query);
    authority->setNext(path);
    schema->setNext(authority);

    return schema;
}

}


