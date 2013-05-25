#include "RFC2396Fragment.h"

namespace URI
{

RFC2396Fragment::RFC2396Fragment():
    RFC2396Handler("fragment", "#.*", ".*", "[^#]+")
{
}

RFC2396Fragment::~RFC2396Fragment()
{
}

}
