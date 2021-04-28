#include <iostream>

//TOUJOURS inclure les headers !!
#include "..\include\sword.h"

using namespace std;

namespace HE_ARC::RPG
{

    int Sword::getFeature() const
    {
        return this->damage;
    }

    string Sword::getName() const
    {
        return "Sword";
    }

}
