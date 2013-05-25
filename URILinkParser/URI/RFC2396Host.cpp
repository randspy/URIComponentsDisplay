#include "RFC2396Host.h"

namespace URI
{

RFC2396Host::RFC2396Host():
    RFC2396Handler("host", "^[^:]+", ".*", "^[^:]+")
{
}

RFC2396Host::~RFC2396Host()
{

}

}
