#include "Necromancer.h"
#include "Hero.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword, int _mana) : Wizard(_strength,_agility, _intelligence, _hp, _name, _sword, _mana)
    {
    }
    /*constructeur par défaut*/
    Necromancer::Necromancer()
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
    void Necromancer::riseUndeads()
    {
        cout << this->name << " wakes up the dead" << endl;
        cout << "Zombies : Wake me up inside" << endl;
        cout << "SAAAAAAAAAAVE ME" << endl;
        cout << "wake me up" << endl << "I can't wake up" << endl;
    }
}