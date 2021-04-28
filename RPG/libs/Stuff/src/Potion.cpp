#include <iostream>

//TOUJOURS inclure les headers !!
#include "..\include\potion.h"

using namespace std;

namespace HE_ARC::RPG
{

    int Potion::getFeature() const
    {
        return this->power;
    }

    string Potion::getName() const
    {
        return "Potion";
    }

}
