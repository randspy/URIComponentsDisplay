#ifndef RFC2396HANDLER_H
#define RFC2396HANDLER_H

#include "URIHandler.h"

#include "MatchedSubStringRetreiver.h"

namespace URI
{

class RFC2396Handler: public URIHandler
{
public:
    virtual ~RFC2396Handler();

protected:
    RFC2396Handler(const std::string& componentName,
                   const std::string& identificationRegex,
                   const std::string& componentValidationRegex,
                   const std::string& componentValueRegex
                   );

public:
    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

protected:
    virtual std::string getComponentValue(const std::string& compWithItsIndicators);
    virtual bool isComponentValid(const std::string& uri);
    virtual void addToComponentsList(DataTypes::Tree<DataTypes::Component>* outputCompTree, DataTypes::Component schema);

    MatchedSubStringRetreiver& getIdentificationRegex() { return _identificationRegex; }

private:
    std::string _componentName;
    MatchedSubStringRetreiver _identificationRegex;
    MatchedSubStringRetreiver _componentValidationRegex;
    MatchedSubStringRetreiver _componentValueRegex;
};

}

#endif // RFC2396HANDLER_H
