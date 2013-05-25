#ifndef RFC2396FRAGMENT_H
#define RFC2396FRAGMENT_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Fragment : public RFC2396Handler
{
public:
    RFC2396Fragment();
    virtual ~RFC2396Fragment();
};

}
#endif // RFC2396FRAGMENT_H
