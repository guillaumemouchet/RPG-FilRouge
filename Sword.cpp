#include <iostream>
#include "Sword.h"

using namespace std;


namespace HE_ARC::RPG
{
    Sword::Sword(int damage) :damage(damage)
    {
        
    }
    int Sword::getDamage() const
    {
        return this->damage;
    }
    
}


   
