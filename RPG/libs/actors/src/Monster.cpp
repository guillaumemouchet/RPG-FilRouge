#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "..\include\Monster.h"

using namespace std;

namespace HE_ARC::RPG
{
    //CONSTUCTEURS
    //par paramètres
    Monster::Monster(int _strength, int _agility, int _intelligence, double _hp)
    {
        cout << "CONSTRUCTEUR par parametres: " << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->currentHp = _hp;
    }

    //DESTRUCTEUR
    Monster::~Monster()
    {
        cout << "DESTRUCTEUR: " << endl;
    }

    //FONCTIONS
    void Monster::show()
    {
        cout << endl
             << "=========================" << endl
             << "Strength : " << this->strength << endl
             << "Health : " << this->hp << endl
             << "Agility : " << this->agility << endl
             << "Intelligence : " << this->intelligence << endl
             << "=========================" << endl
             << endl;
    }

    //SURCHARGE D'OPÉRATEUR AMIE <<
    ostream &operator<<(ostream &s, const Monster &m)
    {
        return s << "=========================" << endl
                 << "Strength : " << m.strength << endl
                 << "Health : " << m.hp << endl
                 << "Agility : " << m.agility << endl
                 << "Intelligence : " << m.intelligence << endl
                 << "=========================" << endl
                 << endl;
    }
    void Monster::looseHp(int _damage, int _stat)
    {
        double damage = 0;
        damage = (_stat * _damage) / 2.0;
        this->currentHp -= damage;
        cout << "votre adversaire perd " << damage << " HP" << endl;
    }
}
