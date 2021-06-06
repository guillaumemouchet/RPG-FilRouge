#include "..\include\Undead.h"
#include "..\include\Monster.h"
#include "..\include\Hero.h"
#include "..\include\Necromancer.h"
#include "..\include\Wizard.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /**
    *@brief Constructeur par paramètre
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    */
    Undead::Undead(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    //liste des sorts du monstre

    /**
    *@brief Le monstre invoque des morts pour blesser le joueur
    *@param _hero pointeur sur le joueur
    */
    void Undead::RiseUndead(Hero *_hero)
    {
        int cDamage = 5;
        cout << "votre adversaire invoque un monstre pour vous blesser" << endl;
        _hero->looseHp(cDamage, this->getStrength());
    }

    /**
    *@brief Le monstre fait perdre des points de mana au joueur si il en posssède sinon rien ne se passe
    *@param _hero pointeur sur le joueur
    */
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

    /**
    *@brief Le monstre aggripe le joueur et lui inflige de lourd dégat
    *@param _hero pointeur sur le joueur
    */
    void Undead::PoisonGrip(Hero *_hero)
    {
        int cDamage = 7;
        cout << "Votre adversaire vous empoigne et vous blesse" << endl;
        _hero->looseHp(cDamage, this->getStrength());
    }
/**
    *@brief permet de définir les attaques du monstre, elles marchent sur un pattern défini, sauf pour Azazel ou c'est aléatoire
    *@param _hero pointeur sur le hero qu'il attaque
    */
    void Undead::MonsterAttack(Hero *_hero)
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
        
        cout << "========================================" << endl;
        Sleep(3000);
    }
}