#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "..\include\hero.h"

using namespace std;

namespace HE_ARC::RPG
{
    //CONSTUCTEURS
    //par défaut
    Hero::Hero()
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
        this->sword = new Sword();
    }
    //par paramètres
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword)
    {
        cout << "CONSTRUCTEUR par parametres: " << _name << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->name = _name;
        //this->sword = _sword;
        this->sword = new Sword(_sword);
    }
    //par recopie
    Hero::Hero(const Hero& hero)
    {
        cout << "CONSTRUCTEUR par recopie: " << hero.name << endl;
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
        this->sword = new Sword(hero.sword->damage);
    }

    //DESTRUCTEUR
    Hero::~Hero()
    {
        cout << "DESTRUCTEUR: " << this->name << endl;
        delete this->sword;
        this->sword = nullptr;
    }


    //FONCTIONS
    void Hero::show()
    {
        cout << endl << "=========================" << endl
        << "Hero's name : " << this->name <<endl
        << "=========================" << endl
        << "Strength : " << this->strength << endl
        << "Health : " << this->hp << endl
        << "Agility : " << this->agility << endl
        << "Intelligence : " << this->intelligence << endl
        << "Sword damage : " << this->sword->getDamage() << endl
        << "=========================" << endl << endl;
    }

  /* void Hero::interact(const Hero& hero )
    {
        cout << this->name << " says hi to " << hero.name << endl;
    } */

    //SURCHARGE D'OPÉRATEUR =
    Hero& Hero::operator=(const Hero &hero)
    {
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
        this->sword = new Sword(hero.sword->damage);
        return *this;
    }

    //SURCHARGE D'OPÉRATEUR AMIE <<
    ostream& operator<<(ostream &s,const Hero &h)
    {
        return s  << "=========================" << endl
        << "Hero's name : " << h.name <<endl
        << "=========================" << endl
        << "Strength : " << h.strength << endl
        << "Health : " << h.hp << endl
        << "Agility : " << h.agility << endl
        << "Intelligence : " << h.intelligence << endl
        << "Sword damage : " << h.sword->getDamage() << endl
        << "=========================" << endl << endl;
    }
}

