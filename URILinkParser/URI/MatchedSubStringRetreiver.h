#ifndef MATCHEDSUBSTRINGRETREIVER_H
#define MATCHEDSUBSTRINGRETREIVER_H

#include <string>
#include <boost/regex.hpp>

namespace URI
{

class MatchedSubStringRetreiver
{
public:
    MatchedSubStringRetreiver(const std::string& regex);
    virtual ~MatchedSubStringRetreiver();

    virtual void serch(const std::string& str);
    virtual bool isMatching() const;
    virtual int getLength() const;
    virtual std::string getMatch() const;

private:
    boost::regex _reg;
    std::string _matchedString;
};

}
#endif // MATCHEDSUBSTRINGRETREIVER_H
