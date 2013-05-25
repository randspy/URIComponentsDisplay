#include "RFC2396Path.h"

namespace URI
{

RFC2396Path::RFC2396Path():
    RFC2396HandlerWithSubComponents("path", "([^/]{2}[^?#]*)", ".*", "[^/][^?#]*")
{
}

RFC2396Path::RFC2396Path(const boost::shared_ptr<URIHandler>& subHandlers):
    RFC2396HandlerWithSubComponents("path", "([^/]{2}[^?#]*)", ".*", "[^/][^?#]*", subHandlers)
{
}

RFC2396Path::~RFC2396Path()
{
}

}
