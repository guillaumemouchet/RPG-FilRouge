#ifndef MONSTER_h
#define MONSTER_h

#include <string>
#include "..\..\Logger.h"
//TOUJOURS inclure les headers !!

using namespace std;

namespace HE_ARC::RPG
{
    class Hero;
    class Monster
    {
    public:
        //CONSTUCTEURS

        //par défaut
        Monster() = default;
        /**
        *@brief Constructeur par paramètre
        *@param _strength la force qui défini les dégats de ses attaques physiques
        *@param _agility l'agilité qui permet d'esquiver les attaques
        *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
        *@param _hp ses points de vie totaux
        */
        Monster(int _strength, int _agility, int _intelligence, double _hp);

        /**
        *@brief Destructeur    
        */
        virtual ~Monster();

        //GETTER
        /**
        *@brief Used to get the stat of the monster
        */
        int getStrength() const { return this->strength; }
        int getAgility() const { return this->agility; }
        int getIntelligence() const { return this->intelligence; }
        double getHp() const { return this->hp; }
        double getcHp() const { return this->currentHp; }
        bool isMAlive() const { return (this->getcHp() > 0); };
        //SETTER
        /**
        *@brief bring alive the monster to reuse him in a futur fight
        */
        void resetcHp() { this->currentHp = hp; }
        //FONCTIONS
        /**
        *@brief Permet de faire perdre des currents hp au monstre
        *@param _damage c'est la constante de dégats de l'attaque du héro
        *@param _stat c'est la compétence du héro, soit de la force ou de l'intelligence
        */
        void looseHp(int _damage, int _stat);
        /**
        *@brief permet d'esquiver les attaques venant du monstre, elle se base sur l'agilité
        *@returns Vrai si l'attaque a été esquivée sinon faux
        */
        bool dodge();
        /**
        *@brief Defines a pattern for the attack of the monster
        *@param _hero pointer on the hero he's attacking
        */
        void virtual monsterAttack(Hero *_hero) = 0;

        //Pour le pattern des monstres
        static int mCounter;

    protected:
        //ATTRIBUTS
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        double hp = 0;
        double currentHp;
    };
}
#endif //Monster_h