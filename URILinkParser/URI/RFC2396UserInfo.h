#ifndef RFC2396USERINFO_H
#define RFC2396USERINFO_H

#include "RFC2396Handler.h"

namespace URI
{

class RFC2396UserInfo : public RFC2396Handler
{
public:
    RFC2396UserInfo();
    virtual ~RFC2396UserInfo();

    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

};

}
#endif // RFC2396USERINFO_H
