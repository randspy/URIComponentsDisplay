#ifndef TREE_H
#define TREE_H

#include <vector>

namespace DataTypes
{

template <typename T>
class Tree
{
public:
    Tree(){}
    ~Tree()
    {
        for(typename std::vector<Tree*>::iterator it = _childs.begin(); it != _childs.end(); ++it)
        {
            delete *it;
        }
    }

    T getValue() const { return _value; }
    void setValue(const T& value) { _value = value; }

    void addChild(Tree* childTree) { _childs.push_back(childTree); }

private:
    Tree(const Tree&);
    Tree& operator=(const Tree&);

private:
    T _value;
    std::vector<Tree*> _childs;
};

}
#endif // TREE_H
