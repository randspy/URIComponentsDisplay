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

    handler.parse("htt.23+.-p://www.ics.uci.edu", tree);
    DataTypes::Component aSchema = tree->getChild(0).getValue();

    QCOMPARE(aSchema.getValue(), std::string("htt.23+.-p"));
    QCOMPARE(aSchema.isValid(), true);
}

void TestRFC2396Schema::schemaIsInvalid()
{
    URI::RFC2396Schema handler;

    DataTypes::Tree<DataTypes::Component>* tree = new DataTypes::Tree<DataTypes::Component>();

    handler.parse("1http://www.ics.uci.edu", tree);
    DataTypes::Component aSchema = tree->getChild(0).getValue();

    QCOMPARE(aSchema.getValue(), std::string("1http"));
    QCOMPARE(aSchema.isValid(), false);

    handler.parse("htt&p://www.ics.uci.edu", tree);
    aSchema = tree->getChild(1).getValue();

    QCOMPARE(aSchema.getValue(), std::string("htt&p"));
    QCOMPARE(aSchema.isValid(), false);
}

}
