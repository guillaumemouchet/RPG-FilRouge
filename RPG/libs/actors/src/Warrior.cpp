#include "..\include\Warrior.h"
#include "..\include\Hero.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /* constructeur par paramètre*/
    Warrior::Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name,Sword _sword) : Hero(_strength,_agility, _intelligence, _hp, _name, _sword)
    {

    }
    /*constructeur par défaut*/
    Warrior::Warrior()
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
        this->sword = new Sword();
    }
    /* Interact of the Warrior is different from hero, it's an override */
    void Warrior::interact(const Hero & hero) 
    {
        
        cout << this->name << " Punch " << hero.getName() << endl;
    }
}