#include "Regex.h"

namespace URI
{

Regex::Regex(const std::string& regex)
    : _reg(regex)
{
}

Regex::~Regex()
{
}

void Regex::serch(const std::string& str)
{
    boost::match_results<std::string::const_iterator> result;

    boost::regex_search(str, result, _reg) ?
        _matchedString = std::string(result[0].first, result[0].second) :
        _matchedString = "";
}

void Regex::match(const std::string &str)
{
    boost::match_results<std::string::const_iterator> result;

    boost::regex_match(str, result, _reg) ?
        _matchedString = std::string(result[0].first, result[0].second) :
        _matchedString = "";
}

bool Regex::isMatching() const
{
    return !_matchedString.empty();
}

int Regex::getLength() const
{
    return _matchedString.length();
}

std::string Regex::getMatch() const
{
    return _matchedString;
}

}
