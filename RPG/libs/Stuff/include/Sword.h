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
        /**
        *@brief Default Constructor
        */
        Sword() : damage(0) {}
         /**
        *@brief Constructor par paramètres
        */
        Sword(int _damage) : damage(_damage) {}
        /**
        *@brief Constructor par recopie
        */
        Sword(Sword &s) : damage(s.damage) {}
        /**
        *@brief default destructor
        */
        ~Sword() = default;
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
        int damage;
    };
}
#endif //Sword_h