#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "..\include\Hero.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"

using namespace std;

namespace HE_ARC::RPG
{
    //CONSTUCTEURS
    //par paramètres
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject) : pObject(_pObject)
    {
        cout << "CONSTRUCTEUR par parametres: " << _name << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->name = _name;
        this->currentHp = _hp;
    }

    //DESTRUCTEUR
    Hero::~Hero()
    {
        cout << "DESTRUCTEUR: " << this->name << endl;
        delete this->pObject;
        this->pObject = nullptr;
    }

    //FONCTIONS
    void Hero::show()
    {
        cout << endl
             << "=========================" << endl
             << "Hero's name : " << this->name << endl
             << "=========================" << endl
             << "Strength : " << this->strength << endl
             << "Health : " << this->hp << endl
             << "Agility : " << this->agility << endl
             << "Intelligence : " << this->intelligence << endl
             << "Object(" << this->pObject->getName() << ") : " << this->pObject->getFeature() << endl
             << "=========================" << endl
             << endl;
    }

    //SURCHARGE D'OPÉRATEUR AMIE <<
    ostream &operator<<(ostream &s, const Hero &h)
    {
        return s << "=========================" << endl
                 << "Hero's name : " << h.name << endl
                 << "=========================" << endl
                 << "Strength : " << h.strength << endl
                 << "Health : " << h.hp << endl
                 << "Agility : " << h.agility << endl
                 << "Intelligence : " << h.intelligence << endl
                 << "Object(" << h.pObject->getName() << ") : " << h.pObject->getFeature() << endl
                 << "=========================" << endl
                 << endl;
    }
    void Hero::equip(IObject *_pObject)
    {
        this->pObject = _pObject;
    }
    IObject *Hero::unequip()
    {
        IObject *mItem = this->pObject;
        this->pObject = nullptr;
        return mItem;
    }
    void Hero::Heal(double _heal)
    {
        if (_heal > this->getHp())
        {
            this->currentHp = this->getHp();
        }
        else
        {
            this->currentHp += _heal;
        }
    }
    void Hero::looseHp(int _damage, int _stat)
    {
        double damage = 0;
        if (typeid(this->pObject) == typeid(Shield))
        {
            damage = (_stat * _damage) / 2.0 - this->pObject->getFeature();
        }
        else
        {
            damage = (_stat * _damage) / 2.0;
        }
        _hero->currentHp -= damage;
        cout << "vous perdez " << damage << " HP" << endl;
    }
    //----------------FONCTION ET CONSTRUCTEUR QUI NE SONT PLUS UTILE--------------------------------------
    //par recopie
    /*
    Hero::Hero(const Hero& hero)
    {
        cout << "CONSTRUCTEUR par recopie: " << hero.name << endl;
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
        this->pObject = new IObject(*hero.pObject);
    }
    */

    /* void Hero::interact(const Hero& hero )
    {
        cout << this->name << " says hi to " << hero.name << endl;
    } */

    //SURCHARGE D'OPÉRATEUR =
    /*
    Hero& Hero::operator=(const Hero &hero)
    {
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
        this->pObject = new IObject(hero.pObject);
        return *this;
    }
    */
}
