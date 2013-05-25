#include "RFC2396Port.h"

namespace URI
{

RFC2396Port::RFC2396Port():
    RFC2396Handler("port", ":[0-9]+", ".*", "[0-9]+")
{
}

RFC2396Port::~RFC2396Port()
{
}

}
