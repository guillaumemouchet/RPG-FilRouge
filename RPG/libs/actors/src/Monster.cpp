#include <iostream>
#include <string>
#include <windows.h>
//TOUJOURS inclure les headers !!
#include "..\include\Monster.h"
#include "..\include\Goblin.h"
#include "..\include\Undead.h"
#include "..\include\Azazel.h"
#include "..\..\Enum.h"

using namespace std;

namespace HE_ARC::RPG
{
    //Compteur pour faire le pattern d'attaque du monstre
    int Monster::mCounter = 0;
    /**
    *@brief Constructeur par paramètre
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    */
    Monster::Monster(int _strength, int _agility, int _intelligence, double _hp)
    {
        //cout << "CONSTRUCTEUR par parametres: " << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->currentHp = _hp;
    }

    /**
    *@brief Destructeur
    
    */
    Monster::~Monster()
    {
        cout << "DESTRUCTEUR: " << endl;
    }
    /**
    *@brief Permet de faire perdre des currents hp au monstre
    *@param _damage c'est la constante de dégats de l'attaque du héro
    *@param _stat c'est la compétence du héro, soit de la force ou de l'intelligence
    */
    void Monster::looseHp(int _damage, int _stat)
    {
        double damage = 0;
        if (this->dodge())
        {
            Logger::writeBattle("Le monstre a esquivé l'attaque");
        }
        else
        {
            damage = (_stat * _damage) / 2.0;
            this->currentHp -= damage;
            Logger::writeBattle("votre adversaire perd " + to_string(damage) + " HP");
        }
    }
    /**
    *@brief permet d'esquiver les attaques venant du monstre, elle se base sur l'agilité
    *@returns Vrai si l'attaque a été esquivée sinon faux
    */
    bool Monster::dodge()
    {
        //return (((rand() % 10 + 1) + this->getAgility()) >= 15);
        srand(time(nullptr));
        return (rand() % 100 + 1 <= this->getAgility());
    }
    

}
