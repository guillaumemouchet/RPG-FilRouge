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
        *@param _strength la force qui défini les dégats de ses attaques physiques
        *@param _agility l'agilité qui permet d'esquiver les attaques
        *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
        *@param _hp ses points de vie totaux
        */
        Goblin(int _strength, int _agility, int _intelligence, double _hp);
        /**
        *@brief Constructeur par default
        */
        Goblin() = default;
        /**
        *@brief destructeur par default
        */
        ~Goblin() = default;


        //liste des sorts du monstre
        /**
        *@brief le monstre demande de l'aide des monstres aux alentours pour blesser le joueur, c'est une attaque physique
        *@param _hero le joueur qui combat le monstre
        */
        void rallye(Hero *_hero);
        /**
        *@brief le monstre essaie de voler le sac du joueur et de le blesser, il a une chance sur 8 de réussir son vol, c'est une attaque physique
        *@param _hero le joueur qui combat le monstre
        */
        void steal(Hero *_hero);
        /**
        *@brief le monstre tire avec une fronde sur le joueur, c'est une attaque magique
        *@param _hero le joueur qui combat le monstre
        */
        void slingShot(Hero *_hero);
        /**
        *@brief permet de définir les attaques du monstre, elles marchent sur un pattern défini
        *@param _hero pointeur sur le hero qu'il attaque
        */
        void monsterAttack(Hero *_hero) override;

    };
    
}
#endif