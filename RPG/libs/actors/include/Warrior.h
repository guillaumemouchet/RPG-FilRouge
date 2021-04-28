#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"
#include "Monster.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Warrior : public Hero
    {
        protected:
        
        public:
        //CONSTRUCTEUR
        //par paramètre
        Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject);
        //par défaut
        Warrior();
        //Destructeur
        ~Warrior() override = default;
        //fonction
        void interact(const Hero &) override;

        //Liste des capacités du Héro
        void Taunt(Monster *_monster);
        void ShieldBash(Monster *_monster);
        void Rampage(Monster *_monster);

    };
    
}
#endif