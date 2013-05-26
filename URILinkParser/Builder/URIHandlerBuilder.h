#ifndef URIHANDLERBUILDER_H
#define URIHANDLERBUILDER_H

#include <boost/shared_ptr.hpp>
#include "../URI/URIHandler.h"

namespace BL
{

class URIHandlerBuilder
{
public:
    URIHandlerBuilder();

    boost::shared_ptr<URI::URIHandler> buildChainOfResponsibility();
};

}

#endif // URIHANDLERBUILDER_H
