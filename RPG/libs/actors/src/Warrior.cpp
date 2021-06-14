#include "..\include\Warrior.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Enum.h"
#include <iostream>
#include <windows.h>
using namespace std;

namespace HE_ARC::RPG
{
    
    Warrior::Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject) : Hero(_strength, _agility, _intelligence, _hp, _name, _pObject)
    {
        this->currentHp = _hp;
    }
    
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

    
    void Warrior::taunt(Monster *_monster)
    {
        cout << this->getName() << " insulte l'adversaire" << endl;
        _monster->looseHp(aWarrior::cTaunt, this->getIntelligence());
    }

    
    void Warrior::shieldBash(Monster *_monster)
    {

        if (typeid(*pObject) == typeid(Shield))
        {
            cout << this->getName() << " frappe violament l'adversaire avec son bouclier" << endl;
            _monster->looseHp(aWarrior::cShieldbash + (this->pObject->getFeature() / 2.0), this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Sword))
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi avec son épée" << endl;
            _monster->looseHp(aWarrior::cShieldbash + (this->pObject->getFeature() / 4.0), this->getStrength());
        }
        else
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi à main nue" << endl;
            _monster->looseHp(aWarrior::cShieldbash, this->getStrength());
        }
    }

    
    void Warrior::rampage(Monster *_monster)
    {
        cout << this->getName() << " Devient fou et frappe tout ce qui bouge" << endl;

        if (typeid(*pObject) == typeid(Sword))
        {
            _monster->looseHp(aWarrior::cRampage + (this->pObject->getFeature()), this->getStrength());
            this->looseHp((aWarrior::cRampage + this->pObject->getFeature()), this->getStrength() / 4.0);
        }
        else
        {
            _monster->looseHp(aWarrior::cRampage, this->getStrength());
            this->looseHp(aWarrior::cRampage, this->getStrength() / 4.0);
        }
    }
    
    void Warrior::heroAttack(Monster *_monster)
    {
        int action = -1;
        int status = 0;
        do
        {

            cout << "[" << aWarrior::rampage << "] Rampage" << endl;
            cout << "[" << aWarrior::shieldbash << "] Shieldbash" << endl;
            cout << "[" << aWarrior::taunt << "] Taunt" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 2 && status == 1));
        
        cout << "========================================" << endl;
        switch (action)
        {
        case aWarrior::rampage:
            this->rampage(_monster);
            break;
        case aWarrior::shieldbash:
            this->shieldBash(_monster);
            break;
        case aWarrior::taunt:
            this->taunt(_monster);
            break;
        default:
            this->heroAttack(_monster);
            break;
        }
        cout << "========================================" << endl;
        Sleep(lTime);
    }
}