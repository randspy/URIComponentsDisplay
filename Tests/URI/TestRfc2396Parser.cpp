#include "TestRfc2396Parser.h"

#include "URILinkParser/URI/RFC2396URIStandardParser.h"

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

    QCOMPARE(aSchema.getValue(), std::string("http"));
}

}


