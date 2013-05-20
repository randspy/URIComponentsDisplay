#ifndef RFC2396URISTANDARDPARSER_H
#define RFC2396URISTANDARDPARSER_H

#include <string>
#include <boost/shared_ptr.hpp>

#include "URIParser.h"
#include "../DataTypes/Component.h"
#include "../DataTypes/Tree.h"

namespace URI
{

class RFC2396URIStandardParser : public URIParser
{
public:
    typedef boost::shared_ptr<DataTypes::Tree<DataTypes::Component> > Components;

public:
    RFC2396URIStandardParser(const std::string& uri);
    virtual ~RFC2396URIStandardParser();

    virtual URIComponents parseURI();
    virtual Components getParsedComponents();

private:
    std::string extractComponent(const std::string& compIndetificationRegex, const std::string& compRegex);

private:
    std::string _uri;
};

}

#endif // RFC2396URISTANDARDPARSER_H
