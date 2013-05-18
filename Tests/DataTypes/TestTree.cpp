#include "TestTree.h"
#include "URILinkParser/DataTypes/Tree.h"

namespace UnitTest
{


TestTree::TestTree()
{
}

void TestTree::addValue()
{
    DataTypes::Tree<std::string> aTree;

    aTree.setValue("value");
    QCOMPARE(aTree.getValue(), std::string("value"));
}

void TestTree::traversal()
{
    DataTypes::Tree<std::string> aTree;
    DataTypes::Tree<std::string>* aTreeChild = new DataTypes::Tree<std::string>();

    aTree.addChild(aTreeChild);

    //TODO: at this moment we don't know what will be the most suiting traversal strategy
}

}
