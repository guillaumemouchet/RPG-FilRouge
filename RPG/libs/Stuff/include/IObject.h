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
        /**
        *@brief Give the name of the item
        *@return a string with the name
        */
        virtual string getName() const = 0;
        /**
        *@brief Give the Feature of the Item
        *@return an int with the value
        */
        virtual int getFeature() const = 0;
        /**
        *@brief Affiche le nom et les caractéristiques de l'objet
        */
        void show() const
        {
            Logger::writeGame(this->getName() + "(" + to_string(this->getFeature()) + ")");
        }
        /**
        *@brief default constructor
        */
        IObject() = default;
        
        /**
        *@brief default destructor
        */
        ~IObject() = default;
    };
}
#endif