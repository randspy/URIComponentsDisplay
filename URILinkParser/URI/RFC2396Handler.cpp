#include "RFC2396Handler.h"

namespace URI
{

RFC2396Handler::~RFC2396Handler()
{
}

RFC2396Handler::RFC2396Handler(const std::string& componentName,
                               const std::string& identificationRegex,
                               const std::string& componentValidationRegex,
                               const std::string& componentValueRegex)
    : _componentName(componentName),
      _identificationRegex(identificationRegex),
      _componentValidationRegex(componentValidationRegex),
      _componentValueRegex(componentValueRegex)
{
}

void RFC2396Handler::parse(const std::string &uri, DataTypes::Tree<DataTypes::Component> *outputCompTree)
{
    _identificationRegex.serch(uri);

    if(_identificationRegex.isMatching())
    {
        DataTypes::Component elem(
                    getComponentValue(_identificationRegex.getMatch()),
                    isComponentValid(_identificationRegex.getMatch()));

        addToComponentsList(outputCompTree, elem);
    }

    URIHandler::parse(uri.substr(_identificationRegex.getLength()), outputCompTree);
}


std::string RFC2396Handler::getComponentValue(const std::string& compWithItsIndicators)
{
    _componentValueRegex.serch(compWithItsIndicators);
    return _componentValueRegex.getMatch();
}

bool RFC2396Handler::isComponentValid(const std::string &uri)
{
    _componentValidationRegex.match(uri);

    if(_componentValidationRegex.isMatching())
    {
        return true;
    }

    return false;
}

void RFC2396Handler::addToComponentsList(DataTypes::Tree<DataTypes::Component> *outputCompTree, DataTypes::Component component)
{
    if(outputCompTree)
    {
        DataTypes::Tree<DataTypes::Component> componentNode;
        componentNode.setValue(component);
        componentNode.setTagName(_componentName);

        outputCompTree->addChild(componentNode);
    }
}


}
