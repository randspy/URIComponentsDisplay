#ifndef RFC2396HANDLERWITHSUBCOMPONENTS_H
#define RFC2396HANDLERWITHSUBCOMPONENTS_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396HandlerWithSubComponents : public RFC2396Handler
{
protected:
    RFC2396HandlerWithSubComponents(const std::string& componentName,
                   const std::string& identificationRegex,
                   const std::string& componentValidationRegex,
                   const std::string& componentValueRegex
                   );

    RFC2396HandlerWithSubComponents(const std::string& componentName,
                   const std::string& identificationRegex,
                   const std::string& componentValidationRegex,
                   const std::string& componentValueRegex,
                   const boost::shared_ptr<URIHandler>& subHandlers
                   );

    virtual ~RFC2396HandlerWithSubComponents();

public:
    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

private:
    void processSubComponentsChain(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

private:
    boost::shared_ptr<URIHandler> _subHandlers;
};

}

#endif // RFC2396HANDLERWITHSUBCOMPONENTS_H
