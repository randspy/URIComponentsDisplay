#include "RFC2396HandlerWithSubComponents.h"

namespace URI
{

RFC2396HandlerWithSubComponents::RFC2396HandlerWithSubComponents
    (const std::string& componentName,
     const std::string& identificationRegex,
     const std::string& componentValidationRegex,
     const std::string& componentValueRegex)
    : RFC2396Handler(componentName, identificationRegex, componentValidationRegex, componentValueRegex)
{
}

RFC2396HandlerWithSubComponents::RFC2396HandlerWithSubComponents
    (const std::string& componentName,
     const std::string& identificationRegex,
     const std::string& componentValidationRegex,
     const std::string& componentValueRegex,
     const boost::shared_ptr<URIHandler>& subHandlers)
    : RFC2396Handler(componentName, identificationRegex, componentValidationRegex, componentValueRegex),
      _subHandlers(subHandlers)
{
}

RFC2396HandlerWithSubComponents::~RFC2396HandlerWithSubComponents()
{
}

void RFC2396HandlerWithSubComponents::parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree)
{
    getIdentificationRegex().serch(uri);

    if(getIdentificationRegex().isMatching())
    {
        std::string componentValue = getComponentValue(getIdentificationRegex().getMatch());
        DataTypes::Component elem(componentValue, isComponentValid(getIdentificationRegex().getMatch()));

        addToComponentsList(outputCompTree, elem);
        processSubComponentsChain(componentValue, outputCompTree);

        URIHandler::parse(uri.substr(getIdentificationRegex().getLength()), outputCompTree);
    }
    else
    {
         URIHandler::parse(uri, outputCompTree);
    }
}

void RFC2396HandlerWithSubComponents::processSubComponentsChain(const std::string &uri, DataTypes::Tree<DataTypes::Component> *outputCompTree)
{
    unsigned int lastAddedChildNumber = outputCompTree->numberOfChilds() - 1;

    if(outputCompTree && _subHandlers.get())
    {
        _subHandlers->parse(uri,
                            &(outputCompTree->getChild(lastAddedChildNumber)));
    }
}

}
