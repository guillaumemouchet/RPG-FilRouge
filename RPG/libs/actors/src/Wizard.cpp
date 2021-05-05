#include "..\include\Wizard.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\..\libs\Battle.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana) : Hero(_strength, _agility, _intelligence, _hp, _name, _pObject)
    {
        mana = _mana;
        cMana = _mana;
        this->currentHp = _hp;
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
        this->pObject = new Sword();
        this->mana = 0;
    }

    //Fonction
    void Wizard::interact(const Hero &hero)
    {
        cout << this->name << " do a magic trick for " << hero.getName() << endl;
    }

    void Wizard::show()
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
             << "Mana : " << this->mana << endl
             << "=========================" << endl
             << endl;
    }

    //Liste des sorts du Héro

    //Lance une puissante boule de feu sur un unique ennemi
    void Wizard::Fireball(Monster *_monster)
    {

        int cDamage = 3; //constante de dégat du sort
        int ManaCost = 5;
        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " lance une violente boule de feu" << endl;
            _monster->looseHp(cDamage ,this->getIntelligence());
            this->cMana -= ManaCost;
        }
        else
        {
            Attack(_monster);
        }
    }

    //Lance un Bizzard qui fait de faible dégats sur tout les ennemis
    void Wizard::Blizzard(Monster *_monster)
    {
        int cDamage = 4;
        int ManaCost = 7;

        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " lance un magnifique Blizzard" << endl;
             _monster->looseHp(cDamage ,this->getIntelligence());
            this->cMana -= ManaCost;

        }
        else
        {
           Attack(_monster);
        }
    }

    //Vole de la vie au monstre et reconvertis un pourcentage en vie
    void Wizard::Leech(Monster *_monster)
    {
        int cDamage = 4;
        int ManaCost = 10;
        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " Inflige des dégats à l'adversaire et se soigne" << endl;
            _monster->looseHp(cDamage , this->getIntelligence());
            this->cMana -= ManaCost;
            this->Heal(cDamage*this->getIntelligence()/2.0);
        }
        else
        {
            Attack(_monster);
        }
    }
    void Wizard::mHeal(double _mHeal)
    {
        if (_mHeal > this->getMana())
        {
            this->cMana = this->getMana();
        }
        else
        {
            this->cMana += _mHeal;
        }
    }
    //Ce sera l'attaque par défaut en cas de manque de mana
    void Wizard::Attack(Monster *_monster)
    {
        if (typeid(*pObject) == typeid(Sword))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton épée" << endl;
            
            _monster->looseHp((this->pObject->getFeature()) ,this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Shield))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton bouclier" << endl;
            _monster->looseHp((this->pObject->getFeature()/2.0) ,this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Potion))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire à main nue" << endl;
            _monster->looseHp(2 ,this->getStrength());
        }
    }

}