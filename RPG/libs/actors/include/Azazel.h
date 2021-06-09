
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
        // constructeurs
        /**
        *@brief Constructeur par défault
        */
        Azazel() = default;
        /**
        *@brief Constructeur par paramètre
        *@param _strength la force qui défini les dégats de ses attaques physiques
        *@param _agility l'agilité qui permet d'esquiver les attaques
        *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
        *@param _hp ses points de vie totaux
        */
        Azazel(int _strength, int _agility, int _intelligence, double _hp);
        /**
        *@brief Destructeur par défault
        */
        ~Azazel() = default;


        //liste des sorts du monstre
        /**
        *@brief Le monstre lance un gigantesque laser sur le joueur, c'est une attaque magique
        *@param _hero le joueur qui combat le monstre
        */
        void brimStorm(Hero *_hero);
        /**
        *@brief Le monstre frappe 2 fois avec un fouet le joueur, c'est une attaque physique
        *@param _hero le joueur qui combat le monstre
        */
        void doubleSlash(Hero *_hero);
        /**
        *@brief Le monstre invoque un cataclysme sur le joueur, c'est une attaque physique
        il y a des dégats aléatoire en rapport à l'objet qu'il se prend
        *@param _hero le joueur qui combat le monstre
        */
        void apocalypse(Hero *_hero);
        /**
        *@brief permet de définir les attaques du monstre, elles sont aléatoires
        *@param _hero pointeur sur le hero qu'il attaque
        */
        void monsterAttack(Hero *_hero) override;
    };

}
#endif