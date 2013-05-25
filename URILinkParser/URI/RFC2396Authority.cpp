#include "RFC2396Authority.h"

#include "MatchedSubStringRetreiver.h"

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
