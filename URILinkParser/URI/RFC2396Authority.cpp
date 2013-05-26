#include "RFC2396Authority.h"

namespace URI
{

RFC2396Authority::RFC2396Authority():
    RFC2396HandlerWithSubComponents("authority", "^//([^/?#]*)", ".*", "[^/]{2}.*")
{
}

RFC2396Authority::RFC2396Authority(const boost::shared_ptr<URIHandler>& subHandlers):
    RFC2396HandlerWithSubComponents("authority", "^//([^/?#]*)", ".*", "[^/]{2}.*", subHandlers)
{
}

RFC2396Authority::~RFC2396Authority()
{
}

}
