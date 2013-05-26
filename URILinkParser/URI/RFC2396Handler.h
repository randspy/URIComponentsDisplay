#ifndef RFC2396HANDLER_H
#define RFC2396HANDLER_H

#include "URIHandler.h"

#include "Regex.h"

namespace URI
{

class RFC2396Handler: public URIHandler
{
protected:
    RFC2396Handler(const std::string& componentName,
                   const std::string& identificationRegex,
                   const std::string& componentValidationRegex,
                   const std::string& componentValueRegex
                   );

public:
    virtual ~RFC2396Handler();

    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

protected:
    virtual std::string getComponentValue(const std::string& compWithItsIndicators);
    virtual bool isComponentValid(const std::string& uri);
    virtual void addToComponentsList(DataTypes::Tree<DataTypes::Component>* outputCompTree, DataTypes::Component schema);

    Regex& getIdentificationRegex() { return _identificationRegex; }
    Regex& getValidationRegex() { return _componentValidationRegex; }

private:
    std::string _componentName;
    Regex _identificationRegex;
    Regex _componentValidationRegex;
    Regex _componentValueRegex;
};

}

#endif // RFC2396HANDLER_H
