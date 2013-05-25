#ifndef RFC2396SCHEMA_H
#define RFC2396SCHEMA_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Schema : public RFC2396Handler
{
public:
    RFC2396Schema();
    virtual ~RFC2396Schema();
};

}

#endif // RFC2396SCHEMA_H
