#include "..\include\Undead.h"
#include "..\include\Monster.h"
#include "..\include\Hero.h"
#include "..\include\Necromancer.h"
#include "..\include\Wizard.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Undead::Undead(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    //liste des sorts du monstre

    //invoque un autre morts vivant pour le rejoindre dans le combat
    void Undead::RiseUndead(Hero *_hero)
    {
        int cDamage = 5;
        cout << "votre adversaire invoque un monstre pour vous blesser" << endl;
        _hero->looseHp(cDamage, this->getStrength());
    }

    //Si la cible est un Wizard ou Necromancer il lui vole une partie de son mana
    void Undead::manaDrain(Hero *_hero)
    {
        int cDamage = 3;
        if (typeid(*_hero) == typeid(Wizard) || typeid(*_hero) == typeid(Necromancer))
        {
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
            cout << "votre adversaire absorbe votre mana" << endl;
            _wizard->looseMana(this->getIntelligence() * cDamage / 2.0);
        }
        else
        {
            cout << "rien ne se passe" << endl;
        }
    }

    //inflige de gros dégat à une cible unique
    void Undead::PoisonGrip(Hero *_hero)
    {
        int cDamage = 7;
        cout << "Votre adversaire vous empoigne et vous blesse" << endl;
        _hero->looseHp(cDamage, this->getStrength());
    }

}