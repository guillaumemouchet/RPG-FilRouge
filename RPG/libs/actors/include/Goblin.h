#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include "Hero.h"
#include <iostream>
#include <ctime>

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
        ~Goblin() = default;
        //liste des sorts du monstre
        void rallye(Hero *_hero);
        void steal(Hero *_hero);
        void slingShot(Hero *_hero);
        void MonsterAttack(Hero *_hero) override;

    };
    
}
#endif