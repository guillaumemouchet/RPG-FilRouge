#include "..\include\Warrior.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include <iostream>
#include <windows.h>
using namespace std;

namespace HE_ARC::RPG
{
     /**
    *@brief Constructeur par paramètre
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    *@param _name son nom prédéfini selon la classe
    *@param _PObject un pointeur sur un objet équipé
    */
    Warrior::Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject) : Hero(_strength, _agility, _intelligence, _hp, _name, _pObject)
    {
        this->currentHp = _hp;
    }
    /**
    *@brief Constructeur par défaut
    */
    Warrior::Warrior()
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
        this->pObject = new Shield();
    }
    /* Interact of the Warrior is different from hero, it's an override */
    void Warrior::interact(const Hero &hero)
    {

        cout << this->name << " Punch " << hero.getName() << endl;
    }

    //Liste des capacités du Héro

    /**
    *@brief Le joueur insulte l'ennemi pour le blesser, c'est une attaque magique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Warrior::Taunt(Monster *_monster)
    {
        int cDamage = 3;
        cout << this->getName() << " insulte l'adversaire" << endl;
        _monster->looseHp(cDamage,this->getIntelligence());
    }

    /**
    *@brief Le joueur frappe avec son bouclier si il en possède un sinon il fait avec ce qu'il a, attaque physique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Warrior::ShieldBash(Monster *_monster)
    {
        int cDamage = 1;
        if (typeid(*pObject) == typeid(Shield))
        {
            cout << this->getName() << " frappe violament l'adversaire avec son bouclier" << endl;
            _monster->looseHp(cDamage  + (this->pObject->getFeature()/2.0) ,this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Sword))
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi avec son épée" << endl;
            _monster->looseHp(cDamage  + (this->pObject->getFeature()/4.0) ,this->getStrength());
        }
        else
        {
            cout << this->getName() << " n'a pas de bouclier mais frappe son ennemi à main nue" << endl;
            _monster->looseHp(cDamage ,this->getStrength());
        }
    }

    /**
    *@brief Le joueur frappe tout ce qui bouge, lui compris, attaque physique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Warrior::Rampage(Monster *_monster)
    {
        int cDamage = 4;
        cout << this->getName() << " Devient fou et frappe tout ce qui bouge" << endl;
        
        if (typeid(*pObject) == typeid(Sword))
        {
            _monster->looseHp(cDamage  + (this->pObject->getFeature()) ,this->getStrength());
            this->looseHp((cDamage  + this->pObject->getFeature()), this->getStrength()/4.0);
        }else
        {
            _monster->looseHp(cDamage ,this->getStrength());
            this->looseHp(cDamage, this->getStrength()/4.0);
        }
    }
    /**
    *@brief Permet au joueur de choisir quelle attaque utiliser en combat, cela dépend de sa classe
    *@param _monster le pointeur sur le monstre qui est combattu
    */
    void Warrior::HeroAttack(Monster *_monster) 
    {
            int action = -1;
            int status = 0;
            do
            {

                cout << "[0] Rampage" << endl;
                cout << "[1] Shieldbash" << endl;
                cout << "[2] Taunt" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
            } while (not(0 <= action && action <= 2 && status == 1));
            Warrior *_warrior = dynamic_cast<Warrior *>(this);
            cout << "========================================" << endl;
            switch (action)
            {
            case 0:
                _warrior->Rampage(_monster);
                break;
            case 1:
                _warrior->ShieldBash(_monster);
                break;
            case 2:
                _warrior->Taunt(_monster);
                break;
            default:
                this->HeroAttack(_monster);
                break;
            }
            cout << "========================================" << endl;
        Sleep(3000);
        
    }
}