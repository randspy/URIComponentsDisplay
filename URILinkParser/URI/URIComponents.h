#ifndef URICOMPONENTS_H
#define URICOMPONENTS_H

#include <string>

namespace URI
{

struct URIComponents
{   
    std::string getSchema() const { return _schema; }
    void setSchema(const std::string& schema) { _schema = schema; }

    std::string getAuthority() const { return _authority; }
    void setAuthority(const std::string& authority) { _authority = authority; }

    std::string getPath() const { return _path; }
    void setPath(const std::string& path) { _path = path; }

    std::string getQuery() const { return _query; }
    void setQuery(const std::string& query) { _query = query; }

    std::string getFragment() const { return _fragments; }
    void setFragments(const std::string& fragments) { _fragments = fragments; }

private:
    std::string _schema;
    std::string _authority;
    std::string _path;
    std::string _query;
    std::string _fragments;
};

}
#endif // URICOMPONENTS_H
