#ifndef RFC2396PATH_H
#define RFC2396PATH_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396Path : public RFC2396Handler
{
public:
    RFC2396Path();
    virtual ~RFC2396Path();
};

}

#endif // RFC2396PATH_H
