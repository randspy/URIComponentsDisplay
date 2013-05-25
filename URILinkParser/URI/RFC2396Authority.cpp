#include "RFC2396Authority.h"

#include "MatchedSubStringRetreiver.h"

namespace URI
{

RFC2396Authority::RFC2396Authority()
{
}

RFC2396Authority::~RFC2396Authority()
{
}

void RFC2396Authority::parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree)
{
    DataTypes::Component authority;
    DataTypes::Tree<DataTypes::Component> componentNode;

    MatchedSubStringRetreiver authorityIdentification("//([^/?#]*)");

    authorityIdentification.serch(uri);
    authorityIdentification.getMatch();

    componentNode.setValue(authority);
    componentNode.setTagName("authority");

    outputCompTree->addChild(componentNode);
}

}
