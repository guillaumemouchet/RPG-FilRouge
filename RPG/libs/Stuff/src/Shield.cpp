#include <iostream>

//TOUJOURS inclure les headers !!
#include "..\include\Shield.h"

using namespace std;

namespace HE_ARC::RPG
{
     /**
    *@brief Donne les caractéristiques de l'objet
    */
     int Shield::getFeature() const
     {
          return this->solidity;
     }
     /**
    *@brief Donne le nom de l'objet
    */
     string Shield::getName() const
     {
          return "Shield";
     }

}
