#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include "Hero.h"
#include <iostream>
#include <ctime>

using namespace std;

namespace HE_ARC::RPG
{
    class Goblin : public Monster
    {
        protected:
        public:
        /**
        *@brief Constructeur par paramètre
        *@param _strength the strength defines the damages of the physical attacks
        *@param _agility The agility is used to dodge the ennemis attack
        *@param _intelligence the intelligence defines the damages of the magical attacks
        *@param _hp it's the total life of the monster
        */
        Goblin(int _strength, int _agility, int _intelligence, double _hp);
        /**
        *@brief Default Constructor
        */
        Goblin() = default;
        /**
        *@brief destructeur par default
        */
        ~Goblin() = default;


        //Monster's spells
        /**
        *@brief the monster calls for help from other monsters, it's a physical attack
        *@param _hero pointer on the hero he's attacking
        */
        void rallye(Hero *_hero);

        /**
        *@brief the monster try to hit and steal the item on top on your backpack, it's a physical attack
        *@param _hero pointer on the hero he's attacking
        */
        void steal(Hero *_hero);
        /**
        *@brief the monster use a slingshot to hit the player,it's a magical attack
        *@param _hero pointer on the hero he's attacking
        */
        void slingShot(Hero *_hero);
        /**
        *@brief Defines a pattern for the attack of the monster
        *@param _hero pointer on the hero he's attacking
        */
        void monsterAttack(Hero *_hero) override;

    };
    
}
#endif