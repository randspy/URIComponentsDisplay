#ifndef RFC2396AUTHORITY_H
#define RFC2396AUTHORITY_H

#include "URIHandler.h"

namespace URI
{

class RFC2396Authority : public URIHandler
{
public:
    RFC2396Authority();
    virtual ~RFC2396Authority();

    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

};

}

#endif // RFC2396AUTHORITY_H
