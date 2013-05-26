#include "TestRegex.h"

#include "URILinkParser/URI/Regex.h"

namespace UnitTest
{

TestRegex::TestRegex()
{
}

void TestRegex::subStringMatch()
{
    URI::Regex matcher("([^:/?#]+):");

    matcher.serch("http://www.ietf.org/rfc/rfc2396.txt");
    QCOMPARE(matcher.isMatching(), true);
    QCOMPARE(matcher.getMatch().c_str(), "http:");
    QCOMPARE(matcher.getLength(), 5);
}

void TestRegex::subStringDoNotMatch()
{
    URI::Regex matcher("([^:/?#]+):");

    matcher.serch("//www.ietf.org/rfc/rfc2396.txt");
    QCOMPARE(matcher.isMatching(), false);
    QCOMPARE(matcher.getMatch().c_str(), "");
    QCOMPARE(matcher.getLength(), 0);
}

void TestRegex::stringMatch()
{
    URI::Regex matcher("[a-z]{2}2[a-z]");

    matcher.match("ww2x");
    QCOMPARE(matcher.isMatching(), true);
    QCOMPARE(matcher.getMatch().c_str(), "ww2x");
    QCOMPARE(matcher.getLength(), 4);
}

}
