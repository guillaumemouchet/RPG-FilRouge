#ifndef WIZARD_H
#define WIZARD_H
#include "Hero.h"
#include "Monster.h"
#include <iostream>

using namespace std;
namespace HE_ARC::RPG
{
    class Wizard : public Hero
    {
        protected:
        int mana;
        public:
        //CONSTUCTEURS
        int cMana;
        //par défaut
        Wizard();
        //par paramètre
        Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana);
        
        //Destructeur
        virtual ~Wizard() override = default;

        //GETTER
        double getcMana() const {return this->cMana;}
        double getMana() const {return this->mana;}
        //Fonctions;
        void interact(const Hero &) override;
        void show();
        void mHeal(double _mHeal);
        //liste des sorts du héros
        void Fireball(Monster *_monster);
        void Blizzard(Monster *_monster);
        void Leech(Monster *_monster);
        void Attack(Monster *_monster);

    };
    
}
#endif