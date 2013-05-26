#include "RFC2396Path.h"

namespace URI
{

RFC2396Path::RFC2396Path():
    RFC2396Handler("path", "^(?!([/]{2}|[?#]))([^?#]*)", ".*", "[^/][^?#]*")
{
}

RFC2396Path::~RFC2396Path()
{
}

}
