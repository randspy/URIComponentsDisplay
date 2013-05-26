#ifndef URIHANDLER_H
#define URIHANDLER_H

#include <string>
#include <boost/shared_ptr.hpp>

#include "../DataTypes/Component.h"
#include "../DataTypes/Tree.h"

namespace URI
{

class URIHandler
{
public:
    URIHandler()
    {
    }
    virtual ~URIHandler()
    {
    }

    void setNext(const boost::shared_ptr<URIHandler>& next)
    {
        if(_nextHandler)
        {
            _nextHandler->setNext(next);
        }
        else
        {
            _nextHandler = next;
        }
    }


    virtual void parse(const std::string& uri, DataTypes::Tree<DataTypes::Component>* outputCompTree)
    {
        if(_nextHandler)
        {
            _nextHandler->parse(uri, outputCompTree);
        }
    }

private:
    boost::shared_ptr<URIHandler> _nextHandler;
};

}
#endif // URIHANDLER_H
