#ifndef WIZARD_H
#define WIZARD_H
#include "Hero.h"
#include "Monster.h"
#include <iostream>

using namespace std;
namespace HE_ARC::RPG
{
    class Wizard : public Hero
    {
        protected:
        int mana;
        int cMana;
        
        public:
        //CONSTUCTEURS
        
        /**
        *@brief Constructeur par défaut
        */
        Wizard();
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
        Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana);
        
        /**
        *@brief Destructeur par défaut
        */
        virtual ~Wizard() = default;

        //GETTER
        /**
        *@brief Used to get the stat of the player 
        */
        double getcMana() const {return this->cMana;}
        double getMana() const {return this->mana;}
        //Fonctions
        /**
        *@brief Interaction between two heroes 
        */
        void interact(const Hero &) override;
        /**
        *@brief Affiche le héro et ses compétences (override car il y le mana en plus)
        */
        void show();
        /**
        *@brief Pour rendre des points de mana au joueur
        *@param _mHeal quantité de mana rendu
        */
        void mHeal(double _mHeal);
        /**
        *@brief pour faire perdre des points de mana au joueur
        *@param _lMana quantité de mana dépensé
        */
        void looseMana(double _lMana);

        //liste des sorts du héros
        /**
        *@brief Le joueur inflige des points de dégats au monstre et les reconvertis en points de vie, attaque magique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void leech(Monster *_monster);
        /**
        *@brief Le joueur frappe avec ce qu'il a sous la main quand il n'a plus de mana, attaque physique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        void attack(Monster *_monster);
        // on ne veut pas que Necromancer ait trop de sort
        /**
        *@brief Le joueur lance une boule de feu sur le monstre, attaque magique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        virtual void fireball(Monster *_monster);
        /**
        *@brief Le joueur invoque un grand blizzard, attaque magique
        *@param _monster pointeur sur le monstre que le joueur attaque
        */
        virtual void blizzard(Monster *_monster);
        /**
        *@brief Permet au joueur de choisir quelle attaque utiliser en combat, cela dépend de sa classe
        *@param _monster le pointeur sur le monstre qui est combattu
        */
        void virtual heroAttack(Monster *_monster)override;

    };
    
}
#endif