#ifndef POTION_h
#define POTION_h

#include "IObject.h"
using namespace std;

namespace HE_ARC::RPG
{
    class Potion : public IObject
    {
    public:
        //CONSTRUCTEURS
        //par défaut
        Potion() : power(0) {}
        //par paramètres
        Potion(int _power) : power(_power) {}
        //par recopie
        Potion(Potion &s) : power(s.power) {}
        ~Potion() = default;
        //GETTER
        /**
        *@brief Give the Feature of the Item
        *@return an int with the value
        */
        int getFeature() const override;
        /**
        *@brief Give the name of the item
        *@return a string with the name
        */
        string getName() const override;

    private:
        //ATTRIBUTS
        int power;
    };
}
#endif 