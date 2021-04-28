#ifndef sword_h
#define sword_h

#include "IObject.h"
using namespace std;

namespace HE_ARC::RPG
{
    class Sword : public IObject
    {
    public:
        //CONSTRUCTEURS
        //par défaut
        Sword() : damage(0) {}
        //par paramètres
        Sword(int _damage) : damage(_damage) {}
        //par recopie
        Sword(Sword &s) : damage(s.damage) {}

        //GETTER
        int getFeature() const override;
        string getName() const override;

    private:
        //ATTRIBUTS
        int damage;
    };
}
#endif //Sword_h