#include "Hero.h"
#include <iostream>
using namespace std;

#include <string>

namespace HE_ARC::RPG
{

    void Hero::show()
    {
        cout << "=========================" << endl;
        cout << "Hero's name : " << this->name <<endl;
        cout << "=========================" << endl;
        cout << "Strength : " << this->strength << endl;
        cout << "Health : " << this->hp << endl;
        cout << "Agility : " << this->agility << endl;
        cout << "Intelligence : " << this->intelligence << endl;
        cout << endl;
    }
    void Hero::interact(const Hero& hero )
    {
        cout << this->name << " says hi to " << hero.name << endl;
    }
    int Hero::getAgility()
    {
        return this->agility;
    }

    Hero::Hero()
    {
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
    }

    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name) 
    {
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->name = _name;
    }
    Hero::Hero(const Hero& hero)
    {
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
    }
}


   
