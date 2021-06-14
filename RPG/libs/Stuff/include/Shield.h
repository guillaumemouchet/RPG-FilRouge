#ifndef SHIELD_h
#define SHIELD_h

#include "IObject.h"
using namespace std;

namespace HE_ARC::RPG
{
    class Shield : public IObject
    {
    public:
        //CONSTRUCTEURS
        /**
        *@brief Default Constructor
        */
        Shield() : solidity(0) {}
        /**
        *@brief Constructor par paramètres
        */
        Shield(int _solidity) : solidity(_solidity) {}
        /**
        *@brief Constructor par recopie
        */
        Shield(Shield &s) : solidity(s.solidity) {}
        /**
        *@brief default destructor
        */
        ~Shield() = default;
        //GETTER
        /**s
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
        int solidity;
    };
}
#endif 