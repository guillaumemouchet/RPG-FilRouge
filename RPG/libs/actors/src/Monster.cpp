#include <iostream>
#include <string>
#include <windows.h>
//TOUJOURS inclure les headers !!
#include "..\include\Monster.h"
#include "..\include\Goblin.h"
#include "..\include\Undead.h"
#include "..\include\Azazel.h"
#include "..\..\Enum.h"

using namespace std;

namespace HE_ARC::RPG
{
    //Compteur pour faire le pattern d'attaque du monstre
    int Monster::mCounter = 0;
    
    Monster::Monster(int _strength, int _agility, int _intelligence, double _hp)
    {
        //cout << "CONSTRUCTEUR par parametres: " << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->currentHp = _hp;
    }

    Monster::~Monster()
    {
        cout << "DESTRUCTEUR: " << endl;
    }
    
    void Monster::looseHp(int _damage, int _stat)
    {
        double damage = 0;
        if (this->dodge())
        {
            Logger::writeBattle("Le monstre a esquivé l'attaque");
        }
        else
        {
            damage = (_stat * _damage) / 2.0;
            this->currentHp -= damage;
            Logger::writeBattle("votre adversaire perd " + to_string(damage) + " HP");
        }
    }
    
    bool Monster::dodge()
    {
        //return (((rand() % 10 + 1) + this->getAgility()) >= 15);
        srand(time(nullptr));
        return (rand() % 100 + 1 <= this->getAgility());
    }
    

}
