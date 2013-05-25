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

private:
    std::string getComponentValue(const std::string& compWithItsIndicators);
    bool isComponentValid(const std::string& uri);
    void addToComponentsList(DataTypes::Tree<DataTypes::Component>* outputCompTree, DataTypes::Component schema);

private:
    std::string _componentName;
    MatchedSubStringRetreiver _identificationRegex;
    MatchedSubStringRetreiver _componentValidationRegex;
    MatchedSubStringRetreiver _componentValueRegex;
};

}

#endif // RFC2396HANDLER_H
