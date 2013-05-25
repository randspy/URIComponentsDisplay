#ifndef RFC2396AUTHORITY_H
#define RFC2396AUTHORITY_H

#include "RFC2396HandlerWithSubComponents.h"

namespace URI
{

class RFC2396Authority : public RFC2396HandlerWithSubComponents
{
public:
    RFC2396Authority();
    RFC2396Authority(const boost::shared_ptr<URIHandler>& subHandlers);

    virtual ~RFC2396Authority();
};

}

#endif // RFC2396AUTHORITY_H
