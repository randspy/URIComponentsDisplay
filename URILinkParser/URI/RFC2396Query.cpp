#include "RFC2396Query.h"

namespace URI
{

RFC2396Query::RFC2396Query():
    RFC2396Handler("query", "\\?[^#]+", ".*", "[^?][^#]+")
{
}

RFC2396Query::~RFC2396Query()
{

}

}
