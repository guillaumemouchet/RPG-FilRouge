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

using namespace std;
namespace HE_ARC::RPG
{
    class Battle
    {
    protected:
    public:
    //CONSTRUCTEUR
    //par défaut
    Battle() = default;
    //création du combat
    void Fight(Hero *_hero, Monster *_monster);
    //vérifie si les personnages sont encore en vie
    bool isHAlive(Hero *_hero);
    bool isMAlive(Monster *_monster);
    //affiche l'état du monstre et du joueur
    void show(Hero *_hero, Monster *_monster);
    //les attaques du monstre
    void MonsterAttack(Monster *_monster, Hero *_hero);
    //les actions et attaque du joueur
    void HeroAction(Hero *_hero,Monster *_monster);
    void HeroAttack(Hero *_hero,Monster *_monster);
    static int hCounter;
    static int mCounter;

    };
}
#endif