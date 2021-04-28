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
    Undead::Undead(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength,_agility, _intelligence, _hp)
    {
        this->currentHp=_hp;
    }
    /*constructeur par défaut*/
    Undead::Undead()
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
    }

    //liste des sorts du monstre

    //invoque un autre morts vivant pour le rejoindre dans le combat
    void Undead::RiseUndead(Hero *_hero)
    {
        cout << "votre adversaire invoque un monstre pour vous blesser" << endl;
        _hero->currentHp -=5;
        cout << "vous perdez 5 HP" << endl;
    }

    //Si la cible est un Wizard ou Necromancer il lui vole une partie de son mana
    void Undead::ManaDrain(Hero *_hero)
    {
        if (typeid(*_hero) == typeid(Wizard)||typeid(*_hero) == typeid(Necromancer))
        {
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
            cout << "votre adversaire absorbe votre mana" << endl;
            _wizard->cMana -=5;
            cout << "vous perdez 5 MP" << endl;
        }else
        {
            cout << "rien ne se passe" <<endl;
        }
    }

    //inflige de gros dégat à une cible unique
    void Undead::PoisonGrip(Hero *_hero)
    {
        cout << "Votre adversaire vous empoigne et vous blesse" << endl;
        _hero->currentHp -=10;
        cout << "vous perdez 5 HP" << endl;
    }
    
    
   
}