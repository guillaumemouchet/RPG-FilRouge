#ifndef NECROMANCER_H
#define NECROMANCER_H
#include "Wizard.h"
#include "Monster.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Necromancer: public Wizard
    {
        protected:
        public:
        //CONSTRUCTEUR
        //par paramètre
        Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *pObject, int Mana);
        //par défaut
        Necromancer()= default;
        //destruveteur
        ~Necromancer() = default;
        
        //Liste des sorts du héro
        void riseUndead(Monster *_monster);
        void cataclysme(Monster *_monster);
        void virtual heroAttack(Monster *_monster) override;
        
       

    };
    
}
#endif