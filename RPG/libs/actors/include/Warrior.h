#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"
#include "Monster.h"
#include <iostream>
using namespace std;
namespace HE_ARC::RPG
{
    class Warrior : public Hero
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
        */
        Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject);
        /**
        *@brief Constructeur par défaut
        */
        Warrior();
        /**
        *@brief Destructeur par défaut
        */
        ~Warrior() = default;
        /**
        *@brief Interaction between two players
        */
        void interact(const Hero &) override;

        //Liste des capacités du Héro
        /**
        *@brief Le joueur insulte l'ennemi pour le blesser, c'est une attaque magique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void taunt(Monster *_monster);
        /**
        *@brief Le joueur frappe avec son bouclier si il en possède un sinon il fait avec ce qu'il a, attaque physique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void shieldBash(Monster *_monster);
        /**
        *@brief Le joueur frappe tout ce qui bouge, lui compris, attaque physique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void rampage(Monster *_monster);
        /**
        *@brief Permet au joueur de choisir quelle attaque utiliser en combat, cela dépend de sa classe
        *@param _monster le pointeur sur le monstre qui est combattu
        */
        void heroAttack(Monster *_monster) override;

    };
    
}
#endif