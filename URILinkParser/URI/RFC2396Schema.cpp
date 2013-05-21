#include "RFC2396Schema.h"

#include "MatchedSubStringRetreiver.h"

namespace URI
{

RFC2396Schema::RFC2396Schema()
{
}

void RFC2396Schema::addSchemaToComponentList(DataTypes::Tree<DataTypes::Component>* outputCompTree, DataTypes::Component schema)
{
    DataTypes::Tree<DataTypes::Component> componentNode;
    componentNode.setValue(schema);

    if(outputCompTree)
    {
        outputCompTree->addChild(componentNode);
    }
}

std::string RFC2396Schema::schemaValue(const std::string& schemaRowElem)
{
    MatchedSubStringRetreiver schemaValueRegex("[^:/?#]+");
    schemaValueRegex.serch(schemaRowElem);
    return schemaValueRegex.getMatch();
}

bool RFC2396Schema::isSchemaValid(const std::string& uri)
{
    MatchedSubStringRetreiver schemaIsValid("[a-zA-Z][a-zA-Z0-9+-.]*:");
    schemaIsValid.match(uri);

    if(schemaIsValid.isMatching())
    {
        return true;
    }

    return false;
}

void RFC2396Schema::parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree)
{
    MatchedSubStringRetreiver schemaIdentification("^(([^:/?#]+):)");

    schemaIdentification.serch(uri);

    if(schemaIdentification.isMatching())
    {
        DataTypes::Component elem(
                    schemaValue(schemaIdentification.getMatch()),
                    isSchemaValid(schemaIdentification.getMatch()));

        addSchemaToComponentList(outputCompTree, elem);
    }

    URIHandler::parse(uri.substr(schemaIdentification.getLength()), outputCompTree);
}

}
