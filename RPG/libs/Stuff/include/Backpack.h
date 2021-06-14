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
        /**
         *@brief default constructor
        */
        Backpack() = default;
        /**
        *@brief default destructor
        */
        ~Backpack() = default;
        /**
         *@brief get the number of items in the backpack
        */
        int getSize() const {return mStack.size();}
        /**
        *@brief Check if the backpack is empty
        *@returns return true if it not emply and false if its empty
        */
        bool isNotEmpty() const;
        /**
        *@brief Unpack the item on the top of the backpack
        *@returns return the item on top of the backpack
        */
        IObject* unPack();
        /**
        *@brief put the item from parameter to put it on top of the backpack
        *@param _pObject pointer on a IObject
        */
        void pack(IObject *_pObject);
    };
}
#endif