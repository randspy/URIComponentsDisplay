#ifndef RFC2396QUERY_H
#define RFC2396QUERY_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Query : public RFC2396Handler
{
public:
    RFC2396Query();
    virtual ~RFC2396Query();
};

}

#endif // RFC2396QUERY_H
