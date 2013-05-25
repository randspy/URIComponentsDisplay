#include "TestTree.h"
#include "URILinkParser/DataTypes/Tree.h"


namespace UnitTest
{


TestTree::TestTree()
{
}

void TestTree::addName()
{
    DataTypes::Tree<std::string> aTree;

    aTree.setTagName("name");
    QCOMPARE(aTree.getTagName(), std::string("name"));
}

void TestTree::addValue()
{
    DataTypes::Tree<std::string> aTree;

    aTree.setValue("value");
    QCOMPARE(aTree.getValue(), std::string("value"));
}

void TestTree::getChilds()
{
    DataTypes::Tree<std::string> aTree;
    DataTypes::Tree<std::string> aTreeChild;

    aTreeChild.setValue("value");
    aTree.addChild(aTreeChild);

    QCOMPARE(aTree.numberOfChilds(), 1u);
    QCOMPARE(aTree.getChild(0).getValue(), std::string("value"));

}

void TestTree::noValidChildAccessChilds()
{
     DataTypes::Tree<std::string> aTree;
     QVERIFY_THROW(aTree.getChild(0), std::out_of_range);
}

void TestTree::traversal()
{
    DataTypes::Tree<std::string> aTree;
    DataTypes::Tree<std::string> aTreeChild;

    aTree.addChild(aTreeChild);

    //TODO: at this moment we don't know what will be the most suiting traversal strategy
}

}
