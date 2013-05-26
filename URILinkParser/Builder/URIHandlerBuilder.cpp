#include "URIHandlerBuilder.h"

#include "../URI/RFC2396Authority.h"
#include "../URI/RFC2396Fragment.h"
#include "../URI/RFC2396Host.h"
#include "../URI/RFC2396Path.h"
#include "../URI/RFC2396Port.h"
#include "../URI/RFC2396Query.h"
#include "../URI/RFC2396Schema.h"
#include "../URI/RFC2396UserInfo.h"

namespace BL
{

URIHandlerBuilder::URIHandlerBuilder()
{
}

boost::shared_ptr<URI::URIHandler> URIHandlerBuilder::buildChainOfResponsibility()
{
    boost::shared_ptr<URI::URIHandler> userInfo =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396UserInfo);

    userInfo->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Host));
    userInfo->setNext( boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Port));

    boost::shared_ptr<URI::URIHandler> schema =
            boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Schema);

    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Authority(userInfo)));
    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Path(userInfo)));
    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Query));
    schema->setNext(boost::shared_ptr<URI::URIHandler>(new URI::RFC2396Fragment));

    return schema;
}

}
