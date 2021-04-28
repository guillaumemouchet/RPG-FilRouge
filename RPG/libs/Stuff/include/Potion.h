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

        //GETTER
        int getFeature() const override;
        string getName() const override;

    private:
        //ATTRIBUTS
        int power;
    };
}
#endif 