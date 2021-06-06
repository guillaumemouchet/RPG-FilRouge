#include "..\include\Wizard.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Logger.h"
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
    *@param _mana le mana qui doit être dépensé pour attaquer
    */
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana) : Hero(_strength, _agility, _intelligence, _hp, _name, _pObject)
    {
        mana = _mana;
        cMana = _mana;
        this->currentHp = _hp;
    }
    /**
    *@brief Constructeur par défaut
    */
    Wizard::Wizard()
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
        this->pObject = new Sword();
        this->mana = 0;
    }

    //Fonction
    void Wizard::interact(const Hero &hero)
    {
        cout << this->name << " do a magic trick for " << hero.getName() << endl;
    }

    /**
    *@brief Affiche le héro et ses compétences (override car il y le mana en plus)
    */
    void Wizard::show()
    {
       /* cout << endl
             << "=========================" << endl
             << "Hero's name : " << this->name << endl
             << "=========================" << endl
             << "Strength : " << this->strength << endl
             << "Health : " << this->hp << endl
             << "Agility : " << this->agility << endl
             << "Intelligence : " << this->intelligence << endl
             << "Object(" << this->pObject->getName() << ") : " << this->pObject->getFeature() << endl
             << "Mana : " << this->mana << endl
             << "=========================" << endl
             << endl;*/
             Logger::writeGame("=========================");
             Logger::writeGame("Hero's name : " + this->name);
             Logger::writeGame("=========================");
             Logger::writeGame("Strength : " + to_string(this->strength));
             Logger::writeGame("Health : " + to_string(this->hp));
             Logger::writeGame("Agility : " + to_string(this->agility));
             Logger::writeGame("Intelligence : " + to_string(this->intelligence));
             Logger::writeGame("Object : "); this->pObject->show();
             Logger::writeGame("Mana : " + to_string(this->mana) );
             Logger::writeGame("=========================");
             Sleep(3000);
    }


    //Liste des sorts du Héro

    /**
    *@brief Le joueur lance une boule de feu sur le monstre, attaque magique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Wizard::Fireball(Monster *_monster)
    {

        int cDamage = 3; //constante de dégat du sort
        int ManaCost = 3;
        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " lance une violente boule de feu" << endl;
            _monster->looseHp(cDamage, this->getIntelligence());
            this->looseMana(ManaCost);
        }
        else
        {
            Attack(_monster);
        }
    }

    /**
    *@brief Le joueur invoque un grand blizzard, attaque magique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Wizard::Blizzard(Monster *_monster)
    {
        int cDamage = 4;
        int ManaCost = 5;

        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " lance un magnifique Blizzard" << endl;
            _monster->looseHp(cDamage, this->getIntelligence());
            this->looseMana(ManaCost);
        }
        else
        {
            Attack(_monster);
        }
    }

    /**
    *@brief Le joueur inflige des points de dégats au monstre et les reconvertis en points de vie, attaque magique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Wizard::Leech(Monster *_monster)
    {
        int cDamage = 4;
        int ManaCost = 8;
        if (this->cMana >= ManaCost)
        {
            cout << this->getName() << " Inflige des dégats à l'adversaire et se soigne" << endl;
            _monster->looseHp(cDamage, this->getIntelligence());
            this->looseMana(ManaCost);
            this->heal((cDamage * this->getIntelligence() / 2.0));
        }
        else
        {
            Attack(_monster);
        }
    }
    /**
    *@brief Pour rendre des points de mana au joueur
    *@param _mHeal quantité de mana rendu
    */
    void Wizard::mHeal(double _mHeal)
    {
        if (_mHeal >= (this->getMana() - this->getcMana()))
        {
            this->cMana = this->getMana();
            Logger::writeBattle("Vous regagnez tous vos Mp.");
        }
        else
        {
            this->cMana += _mHeal;
            Logger::writeBattle("Vous vous soignez de " + to_string(_mHeal) + "Mp.");
        }
    }
    /**
    *@brief pour faire perdre des points de mana au joueur
    *@param _lMana quantité de mana dépensé
    */
    void Wizard::looseMana(double _lMana)
    {
        if (_lMana > this->getcMana())
        {
            this->cMana = 0;
        }
        else
        {
            this->cMana -= _lMana;
        }
        cout << "vous perdez " << _lMana << " MP" << endl;
    }
    /**
    *@brief Le joueur frappe avec ce qu'il a sous la main quand il n'a plus de mana, attaque physique
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Wizard::Attack(Monster *_monster)
    {
        if (typeid(*pObject) == typeid(Sword))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton épée" << endl;

            _monster->looseHp((2 * this->pObject->getFeature()), this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Shield))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton bouclier" << endl;
            _monster->looseHp((2 * this->pObject->getFeature() / 2.0), this->getStrength());
        }
        else if (typeid(*pObject) == typeid(Potion))
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire à main nue" << endl;
            _monster->looseHp(4, this->getStrength());
        }
    }

    /**
    *@brief Permet au joueur de choisir quelle attaque utiliser en combat, cela dépend de sa classe
    *@param _monster le pointeur sur le monstre qui est combattu
    */
    void Wizard::HeroAttack(Monster *_monster)
    {

        int action = -1;
        int status = 0;
        do
        {

            cout << "[0] Fireball (3)" << endl;
            cout << "[1] Blizzard (5)" << endl;
            cout << "[2] Leech (8)" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 2 && status == 1));
        Wizard *_wizard = dynamic_cast<Wizard *>(this);
        cout << "========================================" << endl;

        switch (action)
        {
        case 0:
            _wizard->Fireball(_monster);
            break;
        case 1:
            _wizard->Blizzard(_monster);
            break;
        case 2:
            _wizard->Leech(_monster);
            break;
        default:
            this->HeroAttack(_monster);
            break;
        }

        cout << "========================================" << endl;
        Sleep(3000);
    }
}