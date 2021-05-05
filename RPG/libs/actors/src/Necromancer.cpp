#include "..\include\Necromancer.h"
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
    /*constructeur par paramètre*/
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana) : Wizard(_strength, _agility, _intelligence, _hp, _name, _pObject, _mana)
    {
        this->cMana = _mana;
        this->currentHp = _hp;
    }

    //Liste des sorts du Héro
    //Réveille des monstres pour l'aider dans le combat
    void Necromancer::RiseUndead(Monster *_monster)
    {
        int cDamage = 3;
        int ManaCost = 5;
        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " invoque des morts pour attaquer votre ennemi" << endl;
            this->cMana -= ManaCost;
            _monster->looseHp(cDamage,this->getIntelligence());
        }
        else
        {
          Attack(_monster);
        }
    }

    //Invoque une cataclysme qui blesse tout les ennemis, mais lui fait perdre un quart de sa vie
    void Necromancer::Cataclysme(Monster *_monster)
    {
        int cDamage = 6;
        int ManaCost = 8;
        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " un cataclyme sur votre ennemi" << endl;
            _monster->looseHp(cDamage,this->getIntelligence());
            this->looseHp(cDamage/2.0,this->getIntelligence());
            this->cMana -= ManaCost;
        }
        else
        {
            Attack(_monster);
        }
    }
}
