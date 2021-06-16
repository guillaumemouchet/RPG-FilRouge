#ifndef AZAZEL_H
#define AZAZEL_H

#include "Hero.h"
#include "Monster.h"
#include "Undead.h"
#include <iostream>

using namespace std;

namespace HE_ARC::RPG
{
    class Azazel : public Undead
    {
    protected:
    public:
        /**
        *@brief Default Constructor
        */
        Azazel() = default;

        /**
        *@brief Constructeur par paramètre
        *@param _strength the strength defines the damages of the physical attacks
        *@param _agility The agility is used to dodge the ennemis attack
        *@param _intelligence the intelligence defines the damages of the magical attacks
        *@param _hp it's the total life of the monster
        */
        Azazel(int _strength, int _agility, int _intelligence, double _hp);
        
        /**
        *@brief Destructeur par défault
        */
        ~Azazel() = default;


        //Monster's spells
        /**
        *@brief the monster throw a Laser on the player, it's a magical attack
        *@param _hero pointer on the hero he's attacking
        */
        void brimStorm(Hero *_hero);
        /**
        *@brief The monster hit the player twice with a whip, it's a physical attack
        *@param _hero pointer on the hero he's attacking
        */
        void doubleSlash(Hero *_hero);
        /**
        *@brief The monster creates a cataclysme on the player, it's a physical attack
        There is also a random damage depending on the item he get hit by
        *@param _hero pointer on the hero he's attacking
        */
        void apocalypse(Hero *_hero);
        /**
        *@brief Defines a pattern for the attack of the monster, they are random
        *@param _hero pointer on the hero he's attacking
        */
        void monsterAttack(Hero *_hero) override;
    };

}
#endif