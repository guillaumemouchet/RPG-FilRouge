#ifndef NECROMANCER_H
#define NECROMANCER_H
#include "Wizard.h"
#include "Monster.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Necromancer: public Wizard
    {
        protected:
        public:
        /**
        *@brief Constructeur par paramètre
        *@param _strength la force qui défini les dégats de ses attaques physiques
        *@param _agility l'agilité qui permet d'esquiver les attaques
        *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
        *@param _hp ses points de vie totaux
        *@param _name son nom prédéfini selon la classe
        *@param _PObject un pointeur sur un objet équipé
        *@param _mana le mana qui doit être dépensé pour attaquer
        */
        Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *pObject, int Mana);
        /**
        *@brief Constructeur par défaut
        */
        Necromancer()= default;
        /**
        *@brief Destructeur par défaut
        */
        ~Necromancer() = default;
        
        //Liste des sorts du héro
        /**
        *@brief Le joueur invoque des morts pour blesser son ennemi
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void riseUndead(Monster *_monster);
        /**
        *@brief Le joueur invoque un cataclysme pour blesser l'ennemi, mais se prend des dégats en contre-coup
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void cataclysme(Monster *_monster);
        /**
        *@brief Permet au joueur de choisir quelle attaque utiliser en combat, cela dépend de sa classe
        *@param _monster le pointeur sur le monstre qui est combattu
        */
        void virtual heroAttack(Monster *_monster) override;
        
       

    };
    
}
#endif