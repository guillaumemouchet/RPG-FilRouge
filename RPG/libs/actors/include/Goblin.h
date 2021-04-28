#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include "Hero.h"
#include <iostream>

using namespace std;

namespace HE_ARC::RPG
{
    class Goblin : public Monster
    {
        protected:
        public:
        // constructeurs par défaut et par paramètre
        Goblin(int _strength, int _agility, int _intelligence, double _hp);
        Goblin() = default;
        
        //liste des sorts du monstre
        void Rallye(Hero *_hero);
        void Steal(Hero *_hero);

    };
    
}
#endif