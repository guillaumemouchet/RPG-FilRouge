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
        int damage = 0;
        cout << "votre adversaire invoque un monstre pour vous blesser" << endl;
        damage = (this->getStrength() * cDamage) / 2;
        _hero->currentHp -= damage;
        cout << "vous perdez " << damage << " HP" << endl;
    }

    //Si la cible est un Wizard ou Necromancer il lui vole une partie de son mana
    void Undead::ManaDrain(Hero *_hero)
    {
        int cDamage = 4;
        int damage = 0;
        if (typeid(*_hero) == typeid(Wizard) || typeid(*_hero) == typeid(Necromancer))
        {
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
            cout << "votre adversaire absorbe votre mana" << endl;
            damage = (this->getIntelligence() * cDamage/2);
            _wizard->cMana -= damage;
            cout << "vous perdez " << damage << "MP" << endl;
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
        int damage = 0;
        cout << "Votre adversaire vous empoigne et vous blesse" << endl;
        damage = (this->getStrength() * cDamage) / 2;
        _hero->currentHp -= damage;
        cout << "vous perdez " << damage << " HP" << endl;
    }

}