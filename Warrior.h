#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Warrior : public Hero
    {
        protected:
        
        public:
        Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword);
        Warrior();
        void interact(const Hero &) override;

    };
    
}
#endif