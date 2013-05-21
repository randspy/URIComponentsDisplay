#ifndef URIHANDLER_H
#define URIHANDLER_H

#include <string>

#include "../DataTypes/Component.h"
#include "../DataTypes/Tree.h"

namespace URI
{

class URIHandler
{
public:
    URIHandler() : _nextHandler(NULL)
    {
    }

    void setNext(URIHandler *next)
    {
        _nextHandler = next;
    }


    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree)
    {
        if(_nextHandler)
        {
            _nextHandler->parse(uri, outputCompTree);
        }
    }

private:
    URIHandler *_nextHandler;
};

}
#endif // URIHANDLER_H
