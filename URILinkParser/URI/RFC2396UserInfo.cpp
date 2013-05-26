#include "RFC2396UserInfo.h"

namespace URI
{

RFC2396UserInfo::RFC2396UserInfo():
    RFC2396Handler("user information", "^.*@", ".*", "^[^@]+")
{
}

RFC2396UserInfo::~RFC2396UserInfo()
{
}

void RFC2396UserInfo::parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree)
{
    getIdentificationRegex().serch(uri);

    bool userInfoComponentWasNotYetAddedIntoComponentsTree = !getValidationRegex().isMatching();

    if(getIdentificationRegex().isMatching() && userInfoComponentWasNotYetAddedIntoComponentsTree)
    {
        std::string componentValue = getComponentValue(getIdentificationRegex().getMatch());
        DataTypes::Component elem(componentValue, isComponentValid(getIdentificationRegex().getMatch()));

        addToComponentsList(outputCompTree, elem);

        URIHandler::parse(uri.substr(getIdentificationRegex().getLength()), outputCompTree);
    }
}

}
