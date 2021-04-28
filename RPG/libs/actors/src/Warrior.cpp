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

    //Le héro insulte les ennemi, il se prendra toute les prochaines attaques
    void Warrior::Taunt(Monster *_monster)
    {
        int cDamage = 4;
        double damage = 0;
        cout << this->getName() << " insulte l'adversaire" << endl;
        damage = (this->getIntelligence() * cDamage) / 10.0;
        _monster->currentHp -= damage;
        cout << "votre adversaire perd " << damage << "HP" << endl;
    }

    //le héro frappe violament un ennemi avec son bouclier si il en a un
    void Warrior::ShieldBash(Monster *_monster)
    {
        int cDamage = 5;
        double damage = 0;
        if (typeid(*pObject) == typeid(Shield))
        {
            cout << this->getName() << " frappe violament l'adversaire avec son bouclier" << endl;
            damage = (this->getStrength() * cDamage) / 10.0 + (this->pObject->getFeature());
            _monster->currentHp -= damage;
            cout << "votre adversaire perd " << damage << "HP" << endl;
        }
        else if (typeid(*pObject) == typeid(Sword))
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi avec son épée" << endl;
            damage = (this->getStrength() * cDamage) / 10.0 + (this->pObject->getFeature()) / 2;
            _monster->currentHp -= damage;
            cout << "votre adversaire perd " << damage << "HP" << endl;
        }
        else
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi à main nue" << endl;
            damage = (this->getStrength() * cDamage) / 10.0;
            _monster->currentHp -= damage;
            cout << "votre adversaire perd " << damage << "HP" << endl;
        }
    }

    //le héro frappe violamanent tous les ennemis
    void Warrior::Rampage(Monster *_monster)
    {
        int cDamage = 12;
        double damage = 0;
        cout << this->getName() << " Devient fou et frappe tout ce qui bouge" << endl;
        
        if (typeid(*pObject) == typeid(Sword))
        {
            damage = (this->getStrength() * cDamage) / 10 + this->pObject->getFeature();
        }else
        {
            damage = (this->getStrength() * cDamage) / 10;
        }
        _monster->currentHp -= damage;
        this->currentHp -= damage / 2;
        cout << "votre adversaire perd " << damage << "HP" << endl;
        cout << "vous perdez " << damage / 3 << "HP" << endl;
    }
}