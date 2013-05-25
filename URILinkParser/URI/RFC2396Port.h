#ifndef RFC2396PORT_H
#define RFC2396PORT_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Port : public RFC2396Handler
{
public:
    RFC2396Port();
    virtual ~RFC2396Port();
};

}
#endif // RFC2396PORT_H
