#include "..\include\Backpack.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{

    
    bool Backpack::isNotEmpty() const
    {
        return (not (this->mStack.empty()));
    }
    
    IObject* Backpack::unPack()
    {
        IObject *topStack = this->mStack.top();
        this->mStack.pop();
        return topStack;
    }
    
    void Backpack::pack(IObject * _pObject)
    {
        this->mStack.push(_pObject);
    }
}