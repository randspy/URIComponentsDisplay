#ifndef URIHANDLER_H
#define URIHANDLER_H

namespace URI
{

class URIHandler
{
public:
    URIHandler()
    {
    }

    void setNext(URIHandler *n)
    {
        next = n;
    }


    virtual void handle(const std::string& uri)
    {
        if(next)
        {
            next->handle(uri);
        }
    }

private:
    URIHandler *next;
};

}
#endif // URIHANDLER_H
