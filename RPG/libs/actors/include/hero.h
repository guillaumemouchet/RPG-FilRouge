#ifndef HERO_h
#define HERO_h

#include <string>

//TOUJOURS inclure les headers !!
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Stuff\include\Backpack.h"
#include "..\..\Stuff\include\Potion.h"
using namespace std;

namespace HE_ARC::RPG
{
    class Hero
    {
    public:
        //CONSTUCTEURS
        Backpack backpack;
        double currentHp;
        //par défaut
        Hero() = default;
        //par paramètres
        Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject);
        //par recopie
        Hero(const Hero &hero) = delete;
        
        //DESTRUCTEUR
        virtual ~Hero();

        //GETTER
        //comme il n'y a qu'un return à faire, on peut se permettre de les laisser dans le .h
        int getStrength() const { return this->strength; }
        int getAgility() const { return this->agility; }
        int getIntelligence() const { return this->intelligence; }
        double getHp() const { return this->hp; }
        double getcHp() const {return this->currentHp;}
        string getName() const { return this->name; }

        //FONCTIONS
        void virtual show();
        void virtual interact(const Hero &) = 0;
        void equip(IObject *_pObject);
        IObject* unequip();
        void Heal(double _heal);
        void looseHp(int _damage, int _stat);
        //SURCHARGE D'OPÉRATEUR =
        Hero &operator=(const Hero &hero) = delete;
        
    protected:
        //ATTRIBUTS
        int strength=0;
        int agility=0;
        int intelligence=0;
        double hp=0;
        string name ="NoName";
        IObject *pObject = nullptr;

        //SURCHARGE D'OPÉRATEUR AMIE <<
        friend ostream &operator<<(ostream &s, const Hero &h);
    };
}
#endif //Hero_h