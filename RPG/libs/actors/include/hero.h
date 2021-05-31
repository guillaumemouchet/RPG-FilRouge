#ifndef HERO_h
#define HERO_h

#include <string>
#include <ctime>

//TOUJOURS inclure les headers !!
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Stuff\include\Backpack.h"


using namespace std;

namespace HE_ARC::RPG
{
    class Monster;
    class Hero
    {
    public:
        //CONSTUCTEURS
        Backpack backpack;

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
        double getcHp() const { return this->currentHp; }
        string getName() const { return this->name; }

        void Concede() { this->currentHp=0;}
        //FONCTIONS
        void virtual show();
        void virtual interact(const Hero &) = 0;
        
        void loot();
        void equip(IObject *_pObject);
        IObject *unequip();


        bool isHAlive() const { return (this->getcHp() > 0); }
        void HeroAction(Monster *_monster);
        void HeroAttack(Monster *_monster);
        //utilisation du BackPack
        void UseBackpack(Monster *_monster);

        void heal(double _heal);
        void looseHp(int _damage, int _stat);
        bool dodge();
        //SURCHARGE D'OPÉRATEUR =
        Hero &operator=(const Hero &hero) = delete;

    protected:
        //ATTRIBUTS
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        double hp = 0;
        double currentHp;
        string name = "NoName";
        IObject *pObject = nullptr;

        //SURCHARGE D'OPÉRATEUR AMIE <<
        friend ostream &operator<<(ostream &s, const Hero &h) = delete;
    };
}
#endif //Hero_h