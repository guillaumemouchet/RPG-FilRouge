#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    class IObject
    {
    protected:
    public:
        virtual string getName() const = 0;
        virtual int getFeature() const = 0;
        ~IObject() = default;
    };
}
#endif