#ifndef RFC2396PATH_H
#define RFC2396PATH_H

#include "RFC2396HandlerWithSubComponents.h"

namespace URI
{

class RFC2396Path : public RFC2396HandlerWithSubComponents
{
public:
    RFC2396Path();
    RFC2396Path(const boost::shared_ptr<URIHandler>& subHandlers);
    virtual ~RFC2396Path();
};

}

#endif // RFC2396PATH_H
