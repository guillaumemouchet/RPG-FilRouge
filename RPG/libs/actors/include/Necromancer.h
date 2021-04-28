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
        Necromancer();
        //destruveteur
        virtual ~Necromancer() override = default;
        
        //Liste des sorts du héro
        void RiseUndead(Monster *_monster);
        void Cataclysme(Monster *_monster);

       

    };
    
}
#endif