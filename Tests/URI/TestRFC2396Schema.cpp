#include "TestRFC2396Schema.h"

#include "URILinkParser/URI/RFC2396Schema.h"

namespace UnitTest
{

TestRFC2396Schema::TestRFC2396Schema()
{
}

void TestRFC2396Schema::schemaMatch()
{
    URI::RFC2396Schema handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("http://www.ics.uci.edu", tree);
    DataTypes::Component aSchema = tree->getChild(0).getValue();

    QCOMPARE(aSchema.getValue(), std::string("http"));
}

}
