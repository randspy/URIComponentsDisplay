#include "RFC2396URIStandardParser.h"
#include "../URI/MatchedSubStringRetreiver.h"

namespace URI
{

RFC2396URIStandardParser::RFC2396URIStandardParser(const std::string& uri) : _uri(uri)
{

}

RFC2396URIStandardParser::~RFC2396URIStandardParser()
{

}

URIComponents RFC2396URIStandardParser::parseURI()
{
    //for more details about regular expressions used go to RFC 3986 Appendix B

    URIComponents component;

    component.setSchema(extractComponent("^(([^:/?#]+):)", "[^:/?#]+"));

    if(component.getSchema() != "urn")
    {
        component.setAuthority(extractComponent("(^|//)([^/?#]+)", "[^/?#]+"));
    }

    component.setPath(extractComponent("([^?#]*)", "[^?#]+"));
    component.setQuery(extractComponent("(\\?([^#]*))", "[^?].*"));
    component.setFragments(extractComponent("#(.*)", "[^#].*"));

    return component;
}

std::string RFC2396URIStandardParser::extractComponent(const std::string& compIndetificationRegex, const std::string& compRegex)
{
    MatchedSubStringRetreiver componentIdentification(compIndetificationRegex);

    componentIdentification.serch(_uri);
    if(componentIdentification.isMatching())
    {
        MatchedSubStringRetreiver componentValue(compRegex);
        componentValue.serch(componentIdentification.getMatch());

        _uri = _uri.substr(componentIdentification.getLength());
        if(componentValue.isMatching())
        {
            return componentValue.getMatch();
        }
    }

    return "";
}

}

