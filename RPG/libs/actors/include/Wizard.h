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
        int cMana;
        private:
        
        public:
        //CONSTUCTEURS
        
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
        void looseMana(double _lMana);

        //liste des sorts du héros
        void Leech(Monster *_monster);
        void Attack(Monster *_monster);
        // on ne veut pas que Necromancer ait trop de sort
        virtual void Fireball(Monster *_monster);
        virtual void Blizzard(Monster *_monster);

    };
    
}
#endif