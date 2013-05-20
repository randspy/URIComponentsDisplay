#ifndef TREE_H
#define TREE_H

#include <vector>
#include <stdexcept>

namespace DataTypes
{

template <typename T>
class Tree
{
public:
    Tree(){}
    ~Tree(){}

    T getValue() const { return _value; }
    void setValue(const T& value) { _value = value; }

    void addChild(const Tree& childTree) { _childs.push_back(childTree); }

    unsigned int numberOfChilds() const { return _childs.size(); }

    const Tree& getChild(unsigned int index)
    {
        if(index < numberOfChilds())
        {
            return _childs[index];
        }
        throw std::out_of_range("Child with a given number does not exist");
    }

private:
    T _value;
    std::vector<Tree> _childs;
};

}
#endif // TREE_H
