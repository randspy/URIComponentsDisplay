#ifndef TESTTREE_H
#define TESTTREE_H

#include "../AutoTest.h"

namespace UnitTest
{

class TestTree : public QObject
{
    Q_OBJECT

public:
    TestTree();

private slots:

    void addName();
    void addValue();
    void getChilds();
    void noValidChildAccessChilds();
};


DECLARE_TEST(TestTree)

}
#endif // TESTTREE_H
