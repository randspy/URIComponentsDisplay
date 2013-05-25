#ifndef RFC2396HOST_H
#define RFC2396HOST_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Host : public RFC2396Handler
{
public:
    RFC2396Host();
    virtual ~RFC2396Host();
};

}

#endif // RFC2396HOST_H
