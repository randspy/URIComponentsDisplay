#include "MatchedSubStringRetreiver.h"

namespace URI
{

MatchedSubStringRetreiver::MatchedSubStringRetreiver(const std::string& regex)
    : _reg(regex)
{
}

MatchedSubStringRetreiver::~MatchedSubStringRetreiver()
{
}

void MatchedSubStringRetreiver::serch(const std::string& str)
{
    boost::match_results<std::string::const_iterator> result;
    boost::match_flag_type flags = boost::match_default;

    regex_search(str, result, _reg, flags) ?
        _matchedString = std::string(result[0].first, result[0].second) :
        _matchedString = "";
}

bool MatchedSubStringRetreiver::isMatching() const
{
    return !_matchedString.empty();
}

int MatchedSubStringRetreiver::getLength() const
{
    return _matchedString.length();
}

std::string MatchedSubStringRetreiver::getMatch() const
{
    return _matchedString;
}

}
