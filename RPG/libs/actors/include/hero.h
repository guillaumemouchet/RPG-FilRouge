#ifndef HERO_h
#define HERO_h

#include <string>
#include <ctime>

//TOUJOURS inclure les headers !!
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Stuff\include\Backpack.h"
#include "..\..\Logger.h"


using namespace std;

namespace HE_ARC::RPG
{
    class Monster;
    class Hero
    {
    public:
        //CONSTUCTEURS
        Backpack backpack;

        //par défaut
        /**
        *@brief constructeur par default
        */
        Hero() = default;
        /**
        *@brief constructeur par paramètres
        *@param _strength la force qui défini les dégats de ses attaques physiques
        *@param _agility l'agilité qui permet d'esquiver les attaques
        *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
        *@param _hp ses points de vie totaux
        *@param _name son nom prédéfini selon la classe
        *@param _PObject un pointeur sur un objet équipé
        */
        Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject);
        //par recopie
        Hero(const Hero &hero) = delete;

        /**
        *@brief destructeur, on y détruit les éléments courant et ceux dans le sac
        */
        virtual ~Hero();

        //GETTER
        //comme il n'y a qu'un return à faire, on peut se permettre de les laisser dans le .h
        int getStrength() const { return this->strength; }
        int getAgility() const { return this->agility; }
        int getIntelligence() const { return this->intelligence; }
        double getHp() const { return this->hp; }
        double getcHp() const { return this->currentHp; }
        string getName() const { return this->name; }

        void concede() { this->currentHp=0;}
        //FONCTIONS
        /**
        *@brief Affiche le héro et toutes ses compétences
        */
        void virtual show();
        void virtual interact(const Hero &) = 0;
        
        void loot();
        /**
        *@brief pour équiper un objet dans la main du joueur, depuis son sac
        *@param _PObject un pointeur sur un objet 
        */
        void equip(IObject *_pObject);
        /**
        *@brief Pour désequiper l'objet dans la main du joueur
        *@returns pointeur sur l'objet anciennement équipé
        */
        IObject *unequip();


        bool isHAlive() const { return (this->getcHp() > 0); }
        /**
        *@brief Permet au joueur de choisir qu'elle action faire dans son combat
        *@param _monster le pointeur sur le monstre qui est combattu
        */
        void heroAction(Monster *_monster);
        void virtual heroAttack(Monster *_monster) = 0;
        /**
        *@brief Permet au joueur d'ouvrir son sac et de voir ce qu'il y a dedans, il peut soit l'utiliser, ou non, ou la jeter
        *@param _monster le pointeur sur le monstre qui est combattu
        */
        void useBackpack(Monster *_monster);
        /**
        *@brief Pour rendre des points de vie au héro
        *@param _heal les points de vie qu'il va être rendu
        */
        void heal(double _heal);
        /**
        *@brief Le calcul et la perte de point de vie du héro
        *@param _stat la valeur de la compétence utilisée
        *@param _damage la constante de dégat du sort
        */
        void looseHp(int _damage, int _stat);
        /**
        *@brief Pour que le héro puisse éviter les attaques du monstre, cela dépend de son agilité
        *@returns Vrai si l'attaque a été esquivée sinon faux
        */
        bool dodge();
        //SURCHARGE D'OPÉRATEUR =
        Hero &operator=(const Hero &hero) = delete;

    protected:
        //ATTRIBUTS
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        double hp = 0;
        double currentHp;
        string name = "NoName";
        IObject *pObject = nullptr;

        //SURCHARGE D'OPÉRATEUR AMIE <<
        friend ostream &operator<<(ostream &s, const Hero &h) = delete;
    };
}
#endif //Hero_h