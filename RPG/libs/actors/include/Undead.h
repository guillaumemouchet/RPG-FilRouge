#ifndef UNDEAD_H
#define UNDEAD_H

#include "Monster.h"
#include "Hero.h"
#include <iostream>

using namespace std;

namespace HE_ARC::RPG
{
    class Undead : public Monster
    {
        protected:
        public:
        /**
        *@brief Default Constructor
        */
        Undead()= default;
        /**
        *@brief Constructeur par paramètre
        *@param _strength the strength defines the damages of the physical attacks
        *@param _agility The agility is used to dodge the ennemis attack
        *@param _intelligence the intelligence defines the damages of the magical attacks
        *@param _hp it's the total life of the monster
        */
        Undead(int _strength, int _agility, int _intelligence, double _hp);
        /**
        *@brief destructeur par default
        */
        virtual ~Undead() = default;
        //Monster's spells
        /**
        *@brief Rise an undead from the underground, it's a physical attack
        *@param _hero pointer on the hero he's attacking
        */
        virtual void riseUndead(Hero *_hero);
        /**
        *@brief The monster drain the mana from the player if they have some, it's a magical attack
        *@param _hero pointer on the hero he's attacking
        */
        void manaDrain(Hero *_hero);
        /**
        *@brief Grap the player to damage him, it's a physical attack
        *@param _hero pointer on the hero he's attacking
        */
        virtual void poisonGrip(Hero *_hero);
        /**
        *@brief Defines a pattern for the attack of the monster
        *@param _hero pointer on the hero he's attacking
        */
        void monsterAttack(Hero *_hero)override;

    };
    
}
#endif