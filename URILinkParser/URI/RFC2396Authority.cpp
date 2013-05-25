#include "RFC2396Authority.h"

namespace URI
{

RFC2396Authority::RFC2396Authority():
    RFC2396Handler("authority", "//([^/?#]*)", ".*", "[^/]{2}.*")
{
}

RFC2396Authority::~RFC2396Authority()
{
}

}
