#include "..\include\Wizard.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Logger.h"
#include "..\..\Enum.h"
#include <iostream>
#include <windows.h>
using namespace std;

namespace HE_ARC::RPG
{
   
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana) : Hero(_strength, _agility, _intelligence, _hp, _name, _pObject)
    {
        mana = _mana;
        cMana = _mana;
        this->currentHp = _hp;
    }
    
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

    /**
    *@brief Interaction between two heroes 
    */
    void Wizard::interact(const Hero &hero)
    {
        cout << this->name << " do a magic trick for " << hero.getName() << endl;
    }

    
    void Wizard::show()
    {
       /* cout << endl
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
             << endl;*/
             Logger::writeGame("=========================");
             Logger::writeGame("Hero's name : " + this->name);
             Logger::writeGame("=========================");
             Logger::writeGame("Strength : " + to_string(this->strength));
             Logger::writeGame("Health : " + to_string(this->hp));
             Logger::writeGame("Agility : " + to_string(this->agility));
             Logger::writeGame("Intelligence : " + to_string(this->intelligence));
             Logger::writeGame("Object : "); this->pObject->show();
             Logger::writeGame("Mana : " + to_string(this->mana) );
             Logger::writeGame("=========================");
             Sleep(3000);
    }


    //Liste des sorts du H??ro

    
    void Wizard::fireball(Monster *_monster)
    {


        if (this->cMana >= aWizard::mFireball)
        {
            cout << this->getName() << " lance une violente boule de feu" << endl;
            _monster->looseHp(aWizard::cFireball, this->getIntelligence());
            this->looseMana(aWizard::mFireball);
        }
        else
        {
            attack(_monster);
        }
    }

    
    void Wizard::blizzard(Monster *_monster)
    {
        if (this->cMana >= aWizard::mBlizzard)
        {
            cout << this->getName() << " lance un magnifique Blizzard" << endl;
            _monster->looseHp(aWizard::cBlizzard, this->getIntelligence());
            this->looseMana(aWizard::mBlizzard);
        }
        else
        {
            attack(_monster);
        }
    }

    
    void Wizard::leech(Monster *_monster)
    {

        if (this->cMana >= aWizard::mLeech)
        {
            cout << this->getName() << " Inflige des d??gats ?? l'adversaire et se soigne" << endl;
            _monster->looseHp(aWizard::cLeech, this->getIntelligence());
            this->looseMana(aWizard::mLeech);
            this->heal((aWizard::cLeech * this->getIntelligence() / 2.0));
        }
        else
        {
            attack(_monster);
        }
    }
    
    void Wizard::mHeal(double _mHeal)
    {
        if (_mHeal >= (this->getMana() - this->getcMana()))
        {
            this->cMana = this->getMana();
            Logger::writeBattle("Vous regagnez tous vos Mp.");
        }
        else
        {
            this->cMana += _mHeal;
            Logger::writeBattle("Vous vous soignez de " + to_string(_mHeal) + "Mp.");
        }
    }
    
    void Wizard::looseMana(double _lMana)
    {
        if (_lMana > this->getcMana())
        {
            this->cMana = 0;
        }
        else
        {
            this->cMana -= _lMana;
        }
        cout << "vous perdez " << _lMana << " MP" << endl;
    }
    
    void Wizard::attack(Monster *_monster)
    {
        if (typeid(*pObject) == typeid(Sword))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton ??p??e" << endl;

            _monster->looseHp((2 * this->pObject->getFeature()), this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Shield))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton bouclier" << endl;
            _monster->looseHp((2 * this->pObject->getFeature() / 2.0), this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Potion))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire ?? main nue" << endl;
            _monster->looseHp(2, this->getStrength());
        }
    }

    
    void Wizard::heroAttack(Monster *_monster)
    {

        int action = -1;
        int status = 0;
        do
        {

            cout << "[" << aWizard::fireball << "] Fireball (" << aWizard::mFireball << ")" << endl;
            cout << "[" << aWizard::blizzard << "] Blizzard (" << aWizard::mBlizzard << ")" << endl;
            cout << "[" <<aWizard::leech << "] Leech (" << aWizard::mLeech << ")" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 2 && status == 1));

        cout << "========================================" << endl;

        switch (action)
        {
        case aWizard::fireball:
            this->fireball(_monster);
            break;
        case aWizard::blizzard:
            this->blizzard(_monster);
            break;
        case aWizard::leech:
            this->leech(_monster);
            break;
        default:
            this->heroAttack(_monster);
            break;
        }

        cout << "========================================" << endl;
        Sleep(lTime);
    }
}