#ifndef URIPARSER_H
#define URIPARSER_H

#include "URIComponents.h"

namespace URI
{

class URIParser
{
public:
    URIParser(){}
    virtual ~URIParser(){}

    virtual URIComponents parseURI() = 0;
};

}
#endif // URIPARSER_H
