#ifndef WIZARD_H
#define WIZARD_H
#include "Hero.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Wizard : public Hero
    {
        protected:
        int mana;
        public:
        Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword, int _mana);
        Wizard::Wizard();
        void interact(const Hero &) override;
        void castSpell();
        void show();

    };
    
}
#endif