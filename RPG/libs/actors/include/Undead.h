#ifndef UNDEAD_H
#define UNDEAD_H

#include "Monster.h"
#include "Hero.h"
#include <iostream>

using namespace std;

namespace HE_ARC::RPG
{
    class Undead : public Monster
    {
        protected:
        public:
        // constructeurs
        //par défaut
        Undead()= default;
        //par paramètre
        Undead(int _strength, int _agility, int _intelligence, double _hp);
        
        //liste des sorts du monstre
        void RiseUndead(Hero *_hero);
        void ManaDrain(Hero *_hero);
        void PoisonGrip(Hero *_hero);

       

    };
    
}
#endif