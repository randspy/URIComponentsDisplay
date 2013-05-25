#include "RFC2396UserInfo.h"

namespace URI
{

RFC2396UserInfo::RFC2396UserInfo():
    RFC2396Handler("user information", "^.*@", ".*", "^[^@]+")
{
}

RFC2396UserInfo::~RFC2396UserInfo()
{
}

}
