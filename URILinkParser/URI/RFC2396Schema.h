#ifndef RFC2396SCHEMA_H
#define RFC2396SCHEMA_H

#include "URIHandler.h"

namespace URI
{

class RFC2396Schema : public URIHandler
{
public:
    RFC2396Schema();

    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree);

private:
    bool isSchemaValid(const std::string& uri);
    void addSchemaToComponentList(DataTypes::Tree<DataTypes::Component>* outputCompTree, DataTypes::Component schema);
    std::string schemaValue(const std::string& schemaRowElem);
};

}

#endif // RFC2396SCHEMA_H
