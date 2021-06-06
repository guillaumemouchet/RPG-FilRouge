#include <iostream>

//TOUJOURS inclure les headers !!
#include "..\include\potion.h"

using namespace std;

namespace HE_ARC::RPG
{
    /**
    *@brief Donne les caractéristiques de l'objet
    */
    int Potion::getFeature() const
    {
        return this->power;
    }
    /**
    *@brief Donne le nom de l'objet
    */
    string Potion::getName() const
    {
        return "Potion";
    }

}
