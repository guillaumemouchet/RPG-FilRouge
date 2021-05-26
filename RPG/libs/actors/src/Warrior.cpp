#include "..\include\Warrior.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /* constructeur par paramètre*/
    Warrior::Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject) : Hero(_strength, _agility, _intelligence, _hp, _name, _pObject)
    {
        this->currentHp = _hp;
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
        this->pObject = new Shield();
    }
    /* Interact of the Warrior is different from hero, it's an override */
    void Warrior::interact(const Hero &hero)
    {

        cout << this->name << " Punch " << hero.getName() << endl;
    }

    //Liste des capacités du Héro

    //Le héro insulte les ennemi
    void Warrior::Taunt(Monster *_monster)
    {
        int cDamage = 2;
        cout << this->getName() << " insulte l'adversaire" << endl;
        _monster->looseHp(cDamage,this->getIntelligence());
    }

    //le héro frappe violament un ennemi avec son bouclier si il en a un
    void Warrior::ShieldBash(Monster *_monster)
    {
        int cDamage = 3;
        if (typeid(*pObject) == typeid(Shield))
        {
            cout << this->getName() << " frappe violament l'adversaire avec son bouclier" << endl;
            _monster->looseHp(cDamage  + (this->pObject->getFeature()) ,this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Sword))
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi avec son épée" << endl;
            _monster->looseHp(cDamage  + (this->pObject->getFeature()/2.0) ,this->getStrength());
        }
        else
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi à main nue" << endl;
            _monster->looseHp(cDamage/2.0 ,this->getStrength());
        }
    }

    //le héro frappe violamanent tout ce qui bouge
    void Warrior::Rampage(Monster *_monster)
    {
        int cDamage = 2;
        cout << this->getName() << " Devient fou et frappe tout ce qui bouge" << endl;
        
        if (typeid(*pObject) == typeid(Sword))
        {
            _monster->looseHp(cDamage  + (this->pObject->getFeature()) ,this->getStrength());
            this->looseHp((cDamage  + this->pObject->getFeature()), this->getStrength()/2.0);
        }else
        {
            _monster->looseHp(cDamage ,this->getStrength());
            this->looseHp(cDamage, this->getStrength()/2.0);
        }
    }
}