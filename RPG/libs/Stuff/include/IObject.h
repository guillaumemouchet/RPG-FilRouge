#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>
#include "..\..\Logger.h"
using namespace std;

namespace HE_ARC::RPG
{
    class IObject
    {
    protected:
    public:
        virtual string getName() const = 0;
        virtual int getFeature() const = 0;
        /**
        *@brief Affiche le nom et les caractéristiques de l'objet
        */
        void show() const
        {
            Logger::writeGame(this->getName() + "(" + to_string(this->getFeature()) + ")");
        }
        IObject() = default;
        ~IObject() = default;
    };
}
#endif