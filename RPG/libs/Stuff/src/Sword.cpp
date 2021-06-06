#include <iostream>

//TOUJOURS inclure les headers !!
#include "..\include\sword.h"

using namespace std;

namespace HE_ARC::RPG
{
    /**
    *@brief Donne les caractéristiques de l'objet
    */
    int Sword::getFeature() const
    {
        return this->damage;
    }
    /**
    *@brief Donne le nom de l'objet
    */
    string Sword::getName() const
    {
        return "Sword";
    }

}
