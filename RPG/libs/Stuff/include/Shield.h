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
        //par défaut
        Shield() : solidity(0) {}
        //par paramètres
        Shield(int _solidity) : solidity(_solidity) {}
        //par recopie
        Shield(Shield &s) : solidity(s.solidity) {}

        //GETTER
        int getFeature() const override;
        string getName() const override;

    private:
        //ATTRIBUTS
        int solidity;
    };
}
#endif 