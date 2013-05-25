#ifndef RFC2396AUTHORITY_H
#define RFC2396AUTHORITY_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Authority : public RFC2396Handler
{
public:
    RFC2396Authority();
    virtual ~RFC2396Authority();
};

}

#endif // RFC2396AUTHORITY_H
