#ifndef TESTSUBSTRINGREGEXMATCHER_H
#define TESTSUBSTRINGREGEXMATCHER_H

#include "../AutoTest.h"

namespace UnitTest {

class TestSubStringRegexMatcher : public QObject
{
     Q_OBJECT

public:
    TestSubStringRegexMatcher();

private slots:

    void subStringMatch();
    void subStringDoNotMatch();
};


DECLARE_TEST(TestSubStringRegexMatcher)

}

#endif // TESTSUBSTRINGREGEXMATCHER_H
