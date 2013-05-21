#include "TestMatchedSubStringRetreiver.h"

#include "URILinkParser/URI/MatchedSubStringRetreiver.h"

namespace UnitTest
{

TestSubStringRegexMatcher::TestSubStringRegexMatcher()
{
}

void TestSubStringRegexMatcher::subStringMatch()
{
    URI::MatchedSubStringRetreiver matcher("([^:/?#]+):");

    matcher.serch("http://www.ietf.org/rfc/rfc2396.txt");
    QCOMPARE(matcher.isMatching(), true);
    QCOMPARE(matcher.getMatch().c_str(), "http:");
    QCOMPARE(matcher.getLength(), 5);
}

void TestSubStringRegexMatcher::subStringDoNotMatch()
{
    URI::MatchedSubStringRetreiver matcher("([^:/?#]+):");

    matcher.serch("//www.ietf.org/rfc/rfc2396.txt");
    QCOMPARE(matcher.isMatching(), false);
    QCOMPARE(matcher.getMatch().c_str(), "");
    QCOMPARE(matcher.getLength(), 0);
}

void TestSubStringRegexMatcher::stringMatch()
{
    URI::MatchedSubStringRetreiver matcher("[a-z]{2}2[a-z]");

    matcher.match("ww2x");
    QCOMPARE(matcher.isMatching(), true);
    QCOMPARE(matcher.getMatch().c_str(), "ww2x");
    QCOMPARE(matcher.getLength(), 4);
}

}
