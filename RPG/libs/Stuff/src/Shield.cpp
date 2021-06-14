#include <iostream>

//TOUJOURS inclure les headers !!
#include "..\include\Shield.h"

using namespace std;

namespace HE_ARC::RPG
{
     
     int Shield::getFeature() const
     {
          return this->solidity;
     }
     
     string Shield::getName() const
     {
          return "Shield";
     }

}
