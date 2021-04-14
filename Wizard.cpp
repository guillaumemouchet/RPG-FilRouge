#include "Wizard.h"
#include "Hero.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword, int _mana) : Hero(_strength,_agility, _intelligence, _hp, _name, _sword)
    {
        mana = _mana;
    }
    /*constructeur par défaut*/
    Wizard::Wizard()
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
        this->sword = new Sword();
        this->mana = 0;
    }
    void Wizard::interact(const Hero & hero)
    {
        cout << this->name << " do a magic trick for " << hero.getName() << endl;
    } 

    void Wizard::castSpell()
    {
        cout << this->name << " Cast a Fireball" << endl;
    }
    void Wizard::show()
    {
        cout << endl << "=========================" << endl
        << "Hero's name : " << this->name <<endl
        << "=========================" << endl
        << "Strength : " << this->strength << endl
        << "Health : " << this->hp << endl
        << "Agility : " << this->agility << endl
        << "Intelligence : " << this->intelligence << endl
        << "Sword damage : " << this->sword->getDamage() << endl
        << "Mana : " << this->mana << endl
        << "=========================" << endl << endl;
    }
}