#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>

#include "actors\include\Hero.h"
#include "actors\include\Warrior.h"
#include "actors\include\Wizard.h"
#include "actors\include\Necromancer.h"
#include "actors\include\Monster.h"
#include "actors\include\Goblin.h"
#include "actors\include\Undead.h"
#include "actors\include\Azazel.h"
#include "Stuff\include\IObject.h"
#include "Enum.h"
#include "Logger.h"
using namespace std;
namespace HE_ARC::RPG
{
    class Monster;
    class Hero;

    class Battle
    {
    private:
        /**
        *@brief Affichage des points de vie du monster et du joueur (et du mana si il en )
        *@param _hero le pointeur du joueur
        *@param _monster le pointeur du monstre qu'il combat
        */
        void show(Hero *_hero, Monster *_monster) const;

    public:
        //CONSTRUCTEUR
        /**
        *@brief Constructeur par défault
        */
        Battle() = default;
        //DESTRUCTEUR
        /**
        *@brief Destructeur par défault
        */
        ~Battle() = default;
        /**
        *@brief le joueur combat un monstre, le monstre aura soit un pattern défini ou aura des attaques aléatoire
        *@param _hero le pointeur du joueur
        *@param _monster le pointeur du monstre qu'il combat
        */
        void fight(Hero *_hero, Monster *_monster);
        /**
        *@brief le joueur regagne une partie de ses points de vie et de son mana, il doit aussi trier son sac
        *@param _hero le pointeur du joueur
        *@param _monster le pointeur du monstre qu'il combat
        */
        void restsite(Hero *_hero);
    };
}
#endif