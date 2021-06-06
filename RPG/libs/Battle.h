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
#include "Logger.h"
using namespace std;
namespace HE_ARC::RPG
{
    class Monster;
    class Hero;
    
    class Battle
    {
    private:
        //affiche l'état du monstre et du joueur
        void show(Hero *_hero, Monster *_monster) const;
        
        
    public:
        //CONSTRUCTEUR
        //par défaut ne fait rien
        Battle() = default;
        //DESTRUCTEUR
        ~Battle() = default;
        //création du combat
        void Fight(Hero *_hero, Monster *_monster);
        //création de la zone de repos
        void Restsite(Hero *_hero);
        
    };
}
#endif