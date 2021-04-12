#ifndef NECROMANCER_H
#define NECROMANCER_H
#include "Wizard.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Necromancer: public Wizard
    {
        protected:
        public:
        Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword, int Mana);
        Necromancer();
        void riseUndeads();

       

    };
    
}
#endif