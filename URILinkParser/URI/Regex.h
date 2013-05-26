#ifndef REGEX_H
#define REGEX_H

#include <string>
#include <boost/regex.hpp>

namespace URI
{

class Regex
{
public:
    Regex(const std::string& regex);
    virtual ~Regex();

    virtual void serch(const std::string& str);
    virtual void match(const std::string& str);
    virtual bool isMatching() const;
    virtual int getLength() const;
    virtual std::string getMatch() const;

private:
    boost::regex _reg;
    std::string _matchedString;
};

}
#endif // REGEX_H
