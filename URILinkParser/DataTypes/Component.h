#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

namespace DataTypes {

struct Component
{
    Component():_isValid(false){}
    Component(std::string value, bool valid): _value(value), _isValid(valid){}

    std::string getValue() const { return _value; }
    void setValue(const std::string& value){ _value = value; }

    bool isValid() const { return _isValid; }
    void setValid(bool valid) { _isValid = valid; }

private:
    std::string _value;
    bool _isValid;
};

}

#endif // COMPONENT_H
