#include "RFC2396Schema.h"

namespace URI
{

RFC2396Schema::RFC2396Schema() :
    RFC2396Handler("schema", "^(([^:/?#]+):)", "[a-zA-Z][a-zA-Z0-9+-.]*:", "[^:/?#]+")
{
}

RFC2396Schema::~RFC2396Schema()
{
}

}
