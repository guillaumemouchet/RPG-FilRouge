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

using namespace std;
namespace HE_ARC::RPG
{
    class Battle
    {
    private:
        //vérifie si les personnages sont encore en vie
        bool isHAlive(Hero *_hero) const;
        bool isMAlive(Monster *_monster) const;
        //affiche l'état du monstre et du joueur
        void show(Hero *_hero, Monster *_monster)const;
        //les attaques du monstre
        void MonsterAttack(Monster *_monster, Hero *_hero);
        //les actions et attaque du joueur
        void HeroAction(Hero *_hero, Monster *_monster);
        void HeroAttack(Hero *_hero, Monster *_monster);
        //utilisation du BackPack
        void UseBackpack(Hero *_hero, Monster *_monster);
        //repos entre les combats ou on gagne de la vie et trie le sac
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
        //Pour le pattern des monstres
        static int mCounter;
    };
}
#endif