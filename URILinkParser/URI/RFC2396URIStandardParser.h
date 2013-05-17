#ifndef RFC2396URISTANDARDPARSER_H
#define RFC2396URISTANDARDPARSER_H

#include <string>

#include "URIParser.h"

namespace URI
{

class RFC2396URIStandardParser : public URIParser
{
public:
    RFC2396URIStandardParser(const std::string& uri);
    virtual ~RFC2396URIStandardParser();

    virtual URIComponents parseURI();

private:
    std::string extractComponent(const std::string& compIndetificationRegex, const std::string& compRegex);

private:
    std::string _uri;
};

}

#endif // RFC2396URISTANDARDPARSER_H
