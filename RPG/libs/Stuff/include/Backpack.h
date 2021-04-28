#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <stack>
#include "IObject.h"
using namespace std;
namespace HE_ARC::RPG
{
    class Backpack
    {
    private:
        stack<IObject *> mStack;

    public:
        Backpack() = default;
        ~Backpack() = default;
        int getSize(){return mStack.size();}
        bool isNotEmpty() const;
        IObject *unPack();
        void pack(IObject *);
    };
}
#endif