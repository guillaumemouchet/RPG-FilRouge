#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "..\include\Monster.h"
#include "..\include\Goblin.h"
#include "..\include\Undead.h"
#include "..\include\Azazel.h"

using namespace std;

namespace HE_ARC::RPG
{
    int Monster::mCounter = 0;
    //CONSTUCTEURS
    //par paramètres
    Monster::Monster(int _strength, int _agility, int _intelligence, double _hp)
    {
        //cout << "CONSTRUCTEUR par parametres: " << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->currentHp = _hp;
    }

    //DESTRUCTEUR
    Monster::~Monster()
    {
        cout << "DESTRUCTEUR: " << endl;
    }

    void Monster::looseHp(int _damage, int _stat)
    {
        double damage = 0;
        if (this->dodge())
        {
            cout << "Le monstre a esquivé l'attauqze" << endl;
        }
        else
        {
            damage = (_stat * _damage) / 2.0;
            this->currentHp -= damage;
            cout << "votre adversaire perd " << damage << " HP" << endl;
        }
    }
    bool Monster::dodge()
    {
        //return (((rand() % 10 + 1) + this->getAgility()) >= 15);
        return (rand() % 100 + 1 <= this->getAgility());
    }
    //Les attaques des monstres fonctionnent sur un pattern simple
    void Monster::MonsterAttack(Hero *_hero)
    {
        if (typeid(*this) == typeid(Goblin))
        {
            Goblin *_goblin = dynamic_cast<Goblin *>(this);
            switch (Monster::mCounter)
            {
            case 0:
                _goblin->steal(_hero);
                Monster::mCounter++;
                break;
            case 1:
                _goblin->rallye(_hero);
                Monster::mCounter++;
                break;
            case 2:
                _goblin->slingShot(_hero);
                Monster::mCounter = 0;
            default:
                break;
            }
        }
        if (typeid(*this) == typeid(Undead))
        {
            Undead *_undead = dynamic_cast<Undead *>(this);
            switch (Monster::mCounter)
            {
            case 0:
                _undead->PoisonGrip(_hero);
                Monster::mCounter++;
                break;
            case 1:
                _undead->manaDrain(_hero);
                Monster::mCounter++;
                break;
            case 2:
                _undead->RiseUndead(_hero);
                Monster::mCounter = 0;
                break;
            default:
                break;
            }
        }
        //vu que c'est le boss les attaques sont sur random pour ne pas avoir de pattern
        if (typeid(*this) == typeid(Azazel))
        {
            Azazel *_azazel = dynamic_cast<Azazel *>(this);
            srand(time(nullptr));
            int random = rand() % 3;
            switch (random)
            {
            case 0:
                _azazel->manaDrain(_hero);

                break;
            case 1:
                _azazel->brimStorm(_hero);

                break;
            case 2:
                _azazel->doubleSlash(_hero);
                break;
            case 3:
                _azazel->apocalypse(_hero);
            default:
                //si jamais le random fait une mauvaise valeur (ce qui ne devrait pas mais double protection)
                cout << "Mauvaise Valeur, reessai" << endl;
                this->MonsterAttack( _hero);
                break;
            }
        }
    }

}
